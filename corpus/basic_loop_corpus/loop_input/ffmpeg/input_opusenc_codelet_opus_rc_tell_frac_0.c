#include <stdint.h>
#include <stddef.h>

uint32_t i;
uint32_t rcbuffer;
uint32_t range;

void init_vars() {
    rcbuffer = 0x12345678U;
    range = 0x8000U;
}