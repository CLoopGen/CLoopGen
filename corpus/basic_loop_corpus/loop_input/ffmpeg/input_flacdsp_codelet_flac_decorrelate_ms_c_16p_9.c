#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int len = 1 << 20; // Approximately 1MB of input data per array
int shift = 2;
int i;

int32_t **in;
int16_t **samples;

void init_vars() {
    // Allocate arrays for in[0], in[1], samples[0], samples[1]
    in = (int32_t**)calloc(2, sizeof(int32_t*));
    samples = (int16_t**)calloc(2, sizeof(int16_t*));

    in[0] = (int32_t*)calloc(len, sizeof(int32_t));
    in[1] = (int32_t*)calloc(len, sizeof(int32_t));
    samples[0] = (int16_t*)calloc(len, sizeof(int16_t));
    samples[1] = (int16_t*)calloc(len, sizeof(int16_t));

    // Initialize input data to non-zero values for meaningful computation
    for (int idx = 0; idx < len; idx++) {
        in[0][idx] = rand() % 1000;
        in[1][idx] = rand() % 1000;
    }
}