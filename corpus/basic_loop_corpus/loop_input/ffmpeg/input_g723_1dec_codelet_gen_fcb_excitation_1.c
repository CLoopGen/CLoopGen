#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *vector;
int i;
int cb_gain;
int cb_shift;
int cb_sign;
int cb_pos;
int offset;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of int16_t data (512K elements)
    vector = aligned_alloc(32, data_size * sizeof(int16_t));
    if (!vector) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        vector[idx] = 0;
    }

    cb_gain = 32767;
    cb_shift = 0;
    cb_sign = 0xFF; 
    cb_pos = 0x7FFFFFFF;
}