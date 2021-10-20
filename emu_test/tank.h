#ifndef TANK_H
#define TANK_H

#include "common.h"

#include <QString>
#include <string>

using namespace measuredataset;

inline QString intToHex(uint8_t data) {
    const std::array<char, 16> sym({'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'});
    std::string hex_string(2, 0);
    hex_string[0] = sym[(data >> 4) & 0x0Fu];
    hex_string[1] = sym[data & 0x0Fu];
    return QString::fromStdString(hex_string);
}

struct Tank
{
    int tank_no = 0;
    QString tank_no_xex = "00";
    NP_LVL npl_ = 0.0;
    WATER_LVL wl_ = 0.0;
    TEMPERATURE av_temp_ = 0.0;
    DENCITY_ np_den_ = 0.0;
    VOLUME_ vol_ = 0.0;
    NPMASS_ np_mass_ = 0.0;
};

#endif // TANK_H
