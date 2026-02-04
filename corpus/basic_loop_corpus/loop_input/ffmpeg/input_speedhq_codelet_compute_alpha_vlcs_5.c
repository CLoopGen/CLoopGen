#include <stdint.h>
#include <stdlib.h>

uint16_t level_code[266];
uint8_t level_bits[266];
int16_t level_symbols[266];
int entry = 0;
int i;

void init_vars() {
    for (int idx = 0; idx < 266; ++idx) {
        level_code[idx] = 0;
        level_bits[idx] = 0;
        level_symbols[idx] = 0;
    }
    entry = 0;
}