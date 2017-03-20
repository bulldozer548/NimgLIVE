#include "../std/types.h"

#ifndef NIMGOS_MODULES_H
#define NIMGOS_MODULES_H

void add_module(char *module_name, void *callback);
void remove_module(char *module_name);
void call_module(char *module_name, uint8 argc, char **argv);

#endif //NIMGOS_MODULES_H
