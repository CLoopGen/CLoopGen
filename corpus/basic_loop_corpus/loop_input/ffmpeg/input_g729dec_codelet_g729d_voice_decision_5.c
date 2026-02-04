#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *past_gain_pitch;
int i;
int low_gain_pitch_cnt;

void init_vars() {
    size_t data_size = 134217728; // 256MB / sizeof(int16_t) = 134217728 elements
    past_gain_pitch = (int16_t *)aligned_alloc(_Alignof(int16_t), data_size * sizeof(int16_t));
    for (size_t idx = 0; idx < data_size; idx++) {
        past_gain_pitch[idx] = (int16_t)(idx % 16384); // populate with sample data in range
    }
}