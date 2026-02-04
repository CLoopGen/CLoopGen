#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int len = 1 << 20; // 1 million elements, ~0.01 sec on modern CPU
int shift = 4;
int i;

int32_t **in;
int16_t **samples;

void init_vars() {
    // Allocate two rows for in and samples
    in = (int32_t**)calloc(2, sizeof(int32_t*));
    samples = (int16_t**)calloc(2, sizeof(int16_t*));

    in[0] = (int32_t*)calloc(len, sizeof(int32_t));
    in[1] = (int32_t*)calloc(len, sizeof(int32_t));
    samples[0] = (int16_t*)calloc(len, sizeof(int16_t));
    samples[1] = (int16_t*)calloc(len, sizeof(int16_t));

    // Initialize input data with non-zero values for meaningful computation
    for (int j = 0; j < len; j++) {
        in[0][j] = rand() & 0xFFFF;
        in[1][j] = rand() & 0xFFFF;
    }
}