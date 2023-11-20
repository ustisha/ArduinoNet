#include "../include/SmartNet.h"
#include "../include/NetComponent.h"

void SmartNet::addNetComponent(NetComponent *nc)
{
    if (i >= maxCmp) {
        IF_SERIAL_DEBUG(PSTR("[SmartNet::addNetComponent] Component limit reached\n"));
        return;
    }

    components[i].netComponent = nc;
    IF_SERIAL_DEBUG(printf_P(PSTR("[SmartNet::addNetComponent] Idx: %d\n"), i));
    i++;
}

void SmartNet::commandReceived(Packet *p)
{
    for (int k = 0; k < maxCmp; k++) {
        if (components[k].netComponent != nullptr) {
            components[k].netComponent->receiveHandle(p);
        }
    }
}

void SmartNet::sendInfo(RadioInterface *n, long data, uint8_t cmd) const
{
    Packet p{};
    p.setSender(sender);
    p.setSenderPort(PORT_INFO);
    p.setReceiver(GATEWAY);
    p.setReceiverPort(PORT_HTTP_HANDLER);
    p.setCommand(cmd);
    p.setData(data);

    n->sendData(&p);
}

#ifdef SERIAL_DEBUG

/**
 * Debug net receive. Working with SERIAL_DEBUG defined.
 *
 * To debug will need send string to Serial.
 * Format: <receiver>/<receiver port>/<cmd>/<data>
 * data - only integer values supported now.
 */
void SmartNet::tick()
{
    if (Serial.available() > 0) {
        char str[12];
        Serial.readBytes(str, 12);
        Serial.println(str);

        Packet packet{};
        packet.setSender(GATEWAY);
        packet.setSenderPort(PORT_HTTP_HANDLER);
        char *p = strtok(str, "/");
        uint8_t i = 0;
        int32_t r = -1, port = -1, cmd = -1, data = -1;
        while (p != nullptr) {
            if (i == 0) {
                r = strtol(p, nullptr, 0);
            } else if (i == 1) {
                port = strtol(p, nullptr, 0);
            } else if (i == 2) {
                cmd = strtol(p, nullptr, 0);
            } else if (i == 3) {
                data = strtol(p, nullptr, 0);
            }
            i++;
            p = strtok(nullptr, "/");
        }
        if (r == -1 || port == -1 || cmd == -1) {
            return;
        }
        packet.setReceiver(r);
        packet.setReceiverPort(port);
        packet.setCommand(cmd);
        packet.setData(data);

        /*printf_P(PSTR("[SmartNet::tick] R: %i, RP: %i, Cmd: %i, Data: %ld\n"),
                 packet.getReceiver(),
                 packet.getReceiverPort(),
                 packet.getCommand(),
                 packet.getData());*/

        commandReceived(&packet);
    }
}

#endif
