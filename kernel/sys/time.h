#include "../std/types.h"

#ifndef NIMGOS_TIME_H
#define NIMGOS_TIME_H

struct time_t {
    uint16 year;
    uint8 month;
    uint8 day;
    uint8 hour;
    uint8 minute;
    uint8 second;
};

struct time_t time();

#endif //NIMGOS_TIME_H
