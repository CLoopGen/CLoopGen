#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t * cf_table[16];
uint8_t *lut;
int delta;
unsigned int sx;
unsigned int i;

#define LUT_SIZE (1 << 20)
static uint8_t lut_buffer[LUT_SIZE];
static uint16_t cf_data[16][1 << 14];

void init_vars() {
    delta = 6;

    for (int idx = 0; idx < 16; idx++) {
        cf_table[idx] = cf_data[idx];
        for (int j = 0; j < (1 << 14); j++) {
            cf_data[idx][j] = rand() % ((1 << 14) + 1);
        }
    }

    lut = lut_buffer;
}