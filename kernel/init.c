#include "sys/console.h"
#include "drivers/drivers.h"

void kernel_init() {
    console_init();
    drivers_init();
}