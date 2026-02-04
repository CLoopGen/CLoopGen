#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *buf;
int pitch_lag;
int16_t vector[60];
int i;
int j;

void init_vars() {
    pitch_lag = 4;
    size_t buf_size = 1 << 20;
    buf = aligned_alloc(32, buf_size * sizeof(int16_t));
    for (size_t idx = 0; idx < buf_size; ++idx) {
        buf[idx] = rand() % 1000;
    }
    for (int idx = 0; idx < 60; ++idx) {
        vector[idx] = rand() % 1000;
    }
}