#ifndef RF24NET_H
#define RF24NET_H

//#define SERIAL_DEBUG

#include <Arduino.h>
#include <DebugLog.h>
#include <RadioInterface.h>
#include <RF24Network_config.h>
#include <RF24Network.h>
#include <RF24.h>
#include <SmartNet.h>
#include <Format.h>

#define RF24_DEFAULT_CE 7
#define RF24_DEFAULT_CSN 8
#define RF24_CHANNEL 46
#define RF24_SPI_SPEED_8 8000000

class RF24Net : public RadioInterface {

protected:
    RF24 &radio;
    RF24Network *network;
    uint8_t maxRetry;

    void (*receiveCallback)(Packet *) = nullptr;

public:

    RF24Net(SmartNet *net, uint16_t node, class RF24 &radio, uint8_t level = RF24_PA_LOW);

    bool sendData(Packet *p) override;

    void receiveData(Packet *p) override;

    void onReceiveFunc(void(*callback)(Packet *)) {
        receiveCallback = callback;
    }

    void tick();
};

#endif //RF24NET_H
