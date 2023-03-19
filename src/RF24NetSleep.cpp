#include "../include/RF24NetSleep.h"

bool RF24NetSleep::sendData(Packet *p) {
    radio.powerUp();
    bool status = RF24Net::sendData(p);
    radio.txStandBy();
    radio.powerDown();
    return status;
}
