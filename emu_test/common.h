#ifndef COMMON_H
#define COMMON_H

#define NPLVL "04"
#define WATERLVL "05"
#define AVERAGETEMP "06"
#define DENCITY "08"
#define VOLUME "10"
#define NPMASS "11"
#define ERROR -99


#define STARTDATA "@"
#define ENDDATA "*"
#define DEFDATALEN "00"

#endif // COMMON_H

namespace measuredataset {
    using NP_LVL = double;
    using WATER_LVL = double;
    using TEMPERATURE = double;
    using DENCITY_ = double;
    using VOLUME_ = double;
    using NPMASS_ = double;
} //measuredataset
