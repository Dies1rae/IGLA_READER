#ifndef TANK_H
#define TANK_H

#include "common.h"

#include <QString>

using namespace measuredataset;

struct Tank
{
    QString getTankNoHEX() {
        char hex_string[20];
        sprintf(hex_string, "%X", this->tank_no);
        QString res = hex_string;
        this->tank_no < 10 ? res.insert(0, '0') : res;
        return res;
    }

    int tank_no = 0;
    QString tank_no_xex = "00";
    NP_LVL npl_ = 0.0;
    WATER_LVL wl_ = 0.0;
    TEMPERATURE av_temp_ = 0.0;
};

#endif // TANK_H
