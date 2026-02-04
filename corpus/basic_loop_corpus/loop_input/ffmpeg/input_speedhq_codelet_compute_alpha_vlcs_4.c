#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t level_code[266];
uint8_t level_bits[266];
int16_t level_symbols[266];
int entry;
int i;
int sign;

void init_vars() {
    entry = 0;
}