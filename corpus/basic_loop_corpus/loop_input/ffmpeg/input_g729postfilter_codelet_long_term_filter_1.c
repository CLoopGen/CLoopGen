#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *residual;
int subframe_size;
int i;
int tmp;

void init_vars() {
    subframe_size = 131072;  // Approximately 256KB of int16_t data (131072 * 2 bytes)
    residual = (int16_t*)calloc(subframe_size + (143 + 8 + 1), sizeof(int16_t));
    if (!residual) {
        exit(1);
    }
    for (int idx = 0; idx < subframe_size + (143 + 8 + 1); idx++) {
        residual[idx] = (rand() % 65536) - 32768;
    }
    i = 0;
    tmp = 0;
}