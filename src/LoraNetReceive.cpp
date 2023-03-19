#include "../include/LoraNetReceive.h"

bool LoraNetReceive::sendData(Packet *p) {
    bool status = LoraNet::sendData(p);
    LoRa.receive();
    IF_SERIAL_DEBUG(printf_P(PSTR("[LoraNetReceive::sendData] Receive mode\n")));
    return status;
}
