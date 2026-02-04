#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t prefix;
uint8_t mask;
int extrabytes;

void init_vars() {
    prefix = 0xFF;
    mask = 0x80;
    extrabytes = 0;
}