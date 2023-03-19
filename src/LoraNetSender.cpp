#include "../include/LoraNetSender.h"

LoraNetSender::LoraNetSender(SmartNet *net, uint8_t ss, uint8_t reset, uint8_t dio0) : LoraNet(net, ss, reset, dio0) {
    LoRa.sleep();
    delayMicroseconds(100);
}

bool LoraNetSender::sendData(Packet *p) {
    bool status = LoraNet::sendData(p);
    LoRa.sleep();
    delayMicroseconds(100);
    IF_SERIAL_DEBUG(printf_P(PSTR("[LoraNetSender::sendData] Sleep mode\n")));
    return status;
}
