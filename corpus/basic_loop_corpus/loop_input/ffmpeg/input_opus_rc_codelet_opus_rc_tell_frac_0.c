#include <stdint.h>
#include <stdlib.h>

uint32_t i;
uint32_t rcbuffer;
uint32_t range;

void init_vars() {
    i = 0;
    rcbuffer = 0x12345678U;
    range = 0x8000U;
}