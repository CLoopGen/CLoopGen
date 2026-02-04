#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *fc_v;
uint8_t *tab1;
int pulse_indexes;
int pulse_signs;
int pulse_count;
int bits;
int mask;
int i;

void init_vars() {
    const size_t data_size = 1 << 20; // Approximately 1MB of data
    pulse_count = 100000; // Adjust to ensure loop runs ~0.01 seconds

    fc_v = (int16_t*)aligned_alloc(32, data_size * sizeof(int16_t));
    tab1 = (uint8_t*)aligned_alloc(32, data_size * sizeof(uint8_t));

    for (int j = 0; j < data_size; j++) {
        fc_v[j] = 0;
        tab1[j] = j % 256;
    }

    pulse_indexes = 0x7FFFFF; // Large initial value for bit shifting
    pulse_signs = 0xFFFFF;   // Enough sign bits for 100k iterations
    bits = 2;                // Shift 2 bits per iteration
    mask = 0xFF;             // Mask to index into tab1 safely

    i = 0;
}