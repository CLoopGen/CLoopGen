#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *coef;
int y;
int x;

void init_vars() {
    size_t data_size = 65536; // Ensures ~1MB of data (65536 * 2 bytes)
    coef = (int16_t*)aligned_alloc(_Alignof(int16_t), data_size * sizeof(int16_t));
    for (size_t i = 0; i < data_size; i++) {
        coef[i] = (int16_t)(i % 32768);
    }
}