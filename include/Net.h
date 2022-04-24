#ifndef NET_H
#define NET_H

struct Packet
{
    static const uint8_t PACKET_SIZE = 9;

    uint8_t b[PACKET_SIZE];

    uint8_t getSender()
    {
        return b[0];
    }

    uint8_t getSenderPort()
    {
        return b[1];
    }

    uint8_t getReceiver()
    {
        return b[2];
    }

    uint8_t getReceiverPort()
    {
        return b[3];
    }

    uint8_t getCommand()
    {
        return b[4];
    }

    long getData()
    {
        return (long) b[5] << 24 |
               (long) b[6] << 16 |
               (long) b[7] << 8 |
               (long) b[8];
    }

    void setSender(uint8_t sender)
    {
        b[0] = sender;
    }

    void setSenderPort(uint8_t sp)
    {
        b[1] = sp;
    }

    void setReceiver(uint8_t receiver)
    {
        b[2] = receiver;
    }

    void setReceiverPort(uint8_t rp)
    {
        b[3] = rp;
    }

    void setCommand(uint8_t cmd)
    {
        b[4] = cmd;
    }

    void setData(long data)
    {
        b[5] = (uint8_t) (data >> 24 & 0xFF);
        b[6] = (uint8_t) (data >> 16 & 0xFF);
        b[7] = (uint8_t) (data >> 8 & 0XFF);
        b[8] = (uint8_t) (data & 0XFF);
    }
};

// Components
const uint16_t BROADCAST = 255;
const uint16_t WWW = 254;
const uint16_t GATEWAY = 00;
const uint16_t BATHROOM = 01;
const uint16_t BATHROOM_FLOOR = 011;
const uint16_t BATHROOM_VALVE = 021;
// 031 Not working!
const uint16_t EXHAUSTER = 051;
const uint16_t OUTSIDE_TEMP = 02;
const uint16_t GREENHOUSE = 03;
const uint16_t COLD_CHAMBER = 04;
const uint16_t MAIN_DISPLAY = 05;

// Component ports
const uint8_t PORT_HTTP_HANDLER = 255;
const uint8_t PORT_INFO = 254;
const uint8_t PORT_18B20 = 2;
const uint8_t PORT_BME280 = 3;
const uint8_t PORT_BH1750 = 4;
const uint8_t PORT_VCC = 5;
const uint8_t PORT_VALUE = 6;
const uint8_t PORT_TEMP_CTRL = 7;
const uint8_t PORT_DISPLAY = 8;
const uint8_t PORT_DHT22 = 9;
const uint8_t PORT_LIGHT_CTRL_00 = 10;
const uint8_t PORT_LIGHT_CTRL_01 = 11;
const uint8_t PORT_LIGHT_CTRL_02 = 12;
const uint8_t PORT_LIGHT_CTRL_03 = 13;
const uint8_t PORT_LIGHT_CTRL_04 = 14;
const uint8_t PORT_RTC_CLOCK = 15;
const uint8_t PORT_MOTION_1 = 16;
const uint8_t PORT_MOTION_2 = 17;
const uint8_t PORT_MOTION_3 = 18;
const uint8_t PORT_MOTION_4 = 19;
const uint8_t PORT_MOTION_5 = 20;
const uint8_t PORT_18B20_2 = 21;
const uint8_t PORT_18B20_3 = 22;
const uint8_t PORT_18B20_4 = 23;
const uint8_t PORT_WASHING_MACHINE = 24;
const uint8_t PORT_TVIRTUAL_1 = 25;
const uint8_t PORT_TVIRTUAL_2 = 26;
const uint8_t PORT_TVIRTUAL_3 = 27;
const uint8_t PORT_TVIRTUAL_4 = 28;
const uint8_t PORT_SERVO_00 = 30;
const uint8_t PORT_SERVO_01 = 31;
const uint8_t PORT_SERVO_02 = 32;
const uint8_t PORT_SERVO_03 = 33;
const uint8_t PORT_SERVO_04 = 34;
const uint8_t PORT_RELAY_00 = 35;
const uint8_t PORT_RELAY_01 = 36;
const uint8_t PORT_RELAY_02 = 37;
const uint8_t PORT_RELAY_03 = 38;
const uint8_t PORT_RELAY_04 = 39;
const uint8_t PORT_RELAY_05 = 40;
const uint8_t PORT_RELAY_06 = 41;
const uint8_t PORT_RELAY_07 = 42;
const uint8_t PORT_RELAY_08 = 43;
const uint8_t PORT_RELAY_09 = 44;
const uint8_t PORT_DIMMER_00 = 45;
const uint8_t PORT_DIMMER_01 = 46;
const uint8_t PORT_DIMMER_02 = 47;
const uint8_t PORT_DIMMER_03 = 48;
const uint8_t PORT_DIMMER_04 = 49;
const uint8_t PORT_DIMMER_05 = 50;
const uint8_t PORT_VALUE_2 = 61;
const uint8_t PORT_VALUE_3 = 62;
const uint8_t PORT_VALUE_4 = 63;
const uint8_t PORT_VALUE_5 = 64;
const uint8_t PORT_VALUE_6 = 65;
const uint8_t PORT_VALUE_7 = 66;
const uint8_t PORT_VALUE_8 = 67;
const uint8_t PORT_VALUE_9 = 68;
const uint8_t PORT_TEMP_CTRL_2 = 71;
const uint8_t PORT_TEMP_CTRL_3 = 72;
const uint8_t PORT_TEMP_CTRL_4 = 73;
const uint8_t PORT_TEMP_CTRL_GROUP_1 = 74;
const uint8_t PORT_TEMP_CTRL_GROUP_2 = 75;

// Commands
const uint8_t CMD_TEMPERATURE = 1;
const uint8_t CMD_HUMIDITY = 2;
const uint8_t CMD_PRESSURE = 3;
const uint8_t CMD_LIGHT = 4;
const uint8_t CMD_VCC = 5;
const uint8_t CMD_VALUE = 6;
const uint8_t CMD_GET_VALUES = 7;
const uint8_t CMD_MODE = 8;
const uint8_t CMD_TIMEOUT = 9;
// Temp controller commands
const uint8_t CMD_UP_LIMIT = 10;
const uint8_t CMD_DOWN_LIMIT = 11;
// RTC set time
const uint8_t CMD_RTC_DATE = 12;
const uint8_t CMD_RTC_TIME = 13;
// Free commands
const uint8_t CMD_RELAY = 14;
const uint8_t CMD_MOISTURE = 15;
const uint8_t CMD_MOTION = 16;
// Washing Machine
const uint8_t CMD_WASHING_STATE = 17;
const uint8_t CMD_WASHING_REMAINING_SEC = 18;
const uint8_t CMD_WASHING_DOOR_OPENED = 19;
// Light controller commands
const uint8_t CMD_ACTIVITY_RATIO = 20;
const uint8_t CMD_ACTIVITY_LIMIT = 21;
const uint8_t CMD_RECALL_RATIO = 22;
const uint8_t CMD_RECALL_TIMEOUT = 23;
const uint8_t CMD_TIME_LEFT = 24;
const uint8_t CMD_CALL = 25;
const uint8_t CMD_ENERGY_LEVEL = 26;
const uint8_t CMD_STATE= 27;
// 28, 29
const uint8_t CMD_SERVO_ANGLE = 30;
const uint8_t CMD_SERVO_PERCENT = 31;
const uint8_t CMD_SERVO_MIN_ANGLE = 32;
const uint8_t CMD_SERVO_MAX_ANGLE = 33;
const uint8_t CMD_SERVO_SPEED = 34;
const uint8_t CMD_SERVO_MOVE_TYPE = 35;
// Relays
const uint8_t CMD_RELAY_00 = 40;
const uint8_t CMD_RELAY_01 = 41;
const uint8_t CMD_RELAY_02 = 42;
const uint8_t CMD_RELAY_03 = 43;
const uint8_t CMD_RELAY_04 = 44;
// Relay settings
const uint8_t CMD_RELAY_ON_00 = 45;
const uint8_t CMD_RELAY_ON_01 = 46;
const uint8_t CMD_RELAY_ON_02 = 47;
const uint8_t CMD_RELAY_ON_03 = 48;
const uint8_t CMD_RELAY_ON_04 = 49;
const uint8_t CMD_RELAY_OFF_00 = 145;
const uint8_t CMD_RELAY_OFF_01 = 146;
const uint8_t CMD_RELAY_OFF_02 = 147;
const uint8_t CMD_RELAY_OFF_03 = 148;
const uint8_t CMD_RELAY_OFF_04 = 149;
// Servos
const uint8_t CMD_SERVO_00 = 50;
const uint8_t CMD_SERVO_01 = 51;
const uint8_t CMD_SERVO_02 = 52;
const uint8_t CMD_SERVO_03 = 53;
const uint8_t CMD_SERVO_04 = 54;
// Servo settings
const uint8_t CMD_SERVO_MIN_ANGLE_00 = 55;
const uint8_t CMD_SERVO_MIN_ANGLE_01 = 56;
const uint8_t CMD_SERVO_MIN_ANGLE_02 = 57;
const uint8_t CMD_SERVO_MIN_ANGLE_03 = 58;
const uint8_t CMD_SERVO_MIN_ANGLE_04 = 59;
const uint8_t CMD_SERVO_MAX_ANGLE_00 = 155;
const uint8_t CMD_SERVO_MAX_ANGLE_01 = 156;
const uint8_t CMD_SERVO_MAX_ANGLE_02 = 157;
const uint8_t CMD_SERVO_MAX_ANGLE_03 = 158;
const uint8_t CMD_SERVO_MAX_ANGLE_04 = 159;
const uint8_t CMD_SERVO_RATIO_00 = 160;
const uint8_t CMD_SERVO_RATIO_01 = 161;
const uint8_t CMD_SERVO_RATIO_02 = 162;
const uint8_t CMD_SERVO_RATIO_03 = 163;
const uint8_t CMD_SERVO_RATIO_04 = 164;
// Info
const uint8_t CMD_INFO = 100;

// Data values.
const uint8_t RELAY_DISABLED = -1;
const uint8_t RELAY_ON = 1;
const uint8_t RELAY_OFF = 2;
const uint8_t RELAY_CHANGE = 3;

const uint8_t SERVO_DISABLED = -1;

const uint8_t MODE_AUTO = 1;
const uint8_t MODE_MANUAL = 2;

const uint8_t ENERGY_LVL_OFF = 0;
const uint8_t ENERGY_LVL1 = 1;
const uint8_t ENERGY_LVL2 = 2;

const uint8_t INFO_NETWORK_STARTED = 1;
const uint8_t INFO_DISPLAY_INIT_COMPLETED = 2;
const uint8_t INFO_SETUP_COMPLETED = 9;
const uint8_t INFO_ERROR_DS18B20 = 20;
const uint8_t INFO_ERROR_BME280 = 21;
const uint8_t INFO_ERROR_BH1750 = 22;
const uint8_t INFO_ERROR_SERVO_00 = 50;
const uint8_t INFO_ERROR_SERVO_01 = 51;
const uint8_t INFO_ERROR_SERVO_02 = 52;
const uint8_t INFO_ERROR_SERVO_03 = 53;
const uint8_t INFO_ERROR_SERVO_04 = 54;

#endif //NET_H