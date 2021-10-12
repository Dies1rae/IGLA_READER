#ifndef TANK_H
#define TANK_H

#include "common.h"

#include <QString>

using namespace measuredataset;

inline QString intToHex(const int data) {
    char hex_string[3];
    sprintf(hex_string, "%02X", data);
    return { hex_string };
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
