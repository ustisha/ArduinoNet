#ifndef LORANETSENDER_H
#define LORANETSENDER_H

#include <Arduino.h>
#include <LoraNet.h>

class LoraNetSender : public LoraNet {
public:

    LoraNetSender(SmartNet *net, uint8_t ss, uint8_t reset, uint8_t dio0);

    bool sendData(Packet *p) override;
};

#endif //LORANETSENDER_H
