#include "../std/types.h"

#ifndef NIMGOS_HARDWARE_H
#define NIMGOS_HARDWARE_H

uint8 inportb(uint16 port);
void outportb(uint16 port, uint8 data);

#endif //NIMGOS_HARDWARE_H
