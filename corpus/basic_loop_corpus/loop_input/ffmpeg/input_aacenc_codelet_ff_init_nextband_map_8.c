#include <stdlib.h>
#include <stdint.h>

uint8_t *nextband;
int g;

void init_vars() {
    nextband = (uint8_t*)malloc(128 * sizeof(uint8_t));
    if (!nextband) exit(1);
    g = 0;
}