#include "../include/RF24Net.h"

RF24Net::RF24Net(SmartNet *net, uint16_t node, RF24 &radio, uint8_t level) : RadioInterface(net), radio(radio) {

    network = new RF24Network(radio);

    bool status = radio.begin();
    radio.setPALevel(level);
    radio.setDataRate(RF24_250KBPS);
    radio.setCRCLength(RF24_CRC_8);
    network->begin(RF24_CHANNEL, node);

#ifdef SERIAL_DEBUG
    printf_P(PSTR("[RF24Net] Initialize status: %d, Carrier (-64dBm): %d\n"), status, (int) radio.testCarrier());
    printf_P(PSTR("[RF24Net] MAIN_BUFFER_SIZE: %d\n"), (int) MAIN_BUFFER_SIZE);
#ifdef DISABLE_FRAGMENTATION
    printf_P(PSTR("[RF24Net] DISABLE_FRAGMENTATION: true\n"));
#endif

    radio.printPrettyDetails();
#endif
}

void RF24Net::sendData(Packet *p) {
    IF_SERIAL_DEBUG(
            printf_P(PSTR("[RF24Net::sendData] Sender: %u, Sport: %u, Receiver: %u, Rport: %u, Cmd: %u, Data: %ld\n"),
                     p->getSender(), p->getSenderPort(), p->getReceiver(), p->getReceiverPort(), p->getCommand(),
                     p->getData()));

    RF24NetworkHeader header(p->getReceiver());
    bool status = network->write(header, &p->b, Packet::PACKET_SIZE);

    IF_SERIAL_DEBUG(printf_P(PSTR("[RF24Net::sendData] Sent. Status: %d\n"), (int) status));
}

void RF24Net::receiveData(Packet *p) {

    IF_SERIAL_DEBUG(
            printf_P(
                    PSTR("[RF24Net::receiveData] Receive. Sender: %u, Sport: %u, Receiver: %u, Rport: %u, Cmd: %u, Data: %ld\n"),
                    p->getSender(), p->getSenderPort(), p->getReceiver(), p->getReceiverPort(),
                    p->getCommand(), p->getData()));

    if (p->getReceiver() != smartNet->sender && p->getReceiver() != BROADCAST) {
        return;
    }

    if (nullptr != receiveCallback) {
        IF_SERIAL_DEBUG(PSTR("[RF24Net::receiveData] Receive Callback\n"));
        receiveCallback(p);
    }

    smartNet->commandReceived(p);
}

void RF24Net::tick() {
    network->update();

    while (network->available()) {
        RF24NetworkHeader header;
        Packet p{};
        network->read(header, &p.b, Packet::PACKET_SIZE);
        // @todo receiveData call sendData for confirmation but immediately write not working.
        delay(10);
        receiveData(&p);
    }
}