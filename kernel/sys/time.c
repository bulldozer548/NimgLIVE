#include "time.h"
#include "hardware.h"

uint8 request(uint8 data) {
    outportb(0x70, data);
    data = inportb(0x71);
    return data - (data / 16) * 6;
}

struct time_t time() {
    struct time_t clock;
    outportb(0x70, 0x95);

    clock.year = request(9);
    clock.month = request(8);
    clock.day = request(7);
    clock.hour = request(4);
    clock.minute = request(2);
    clock.second = request(0);

    return clock;
}