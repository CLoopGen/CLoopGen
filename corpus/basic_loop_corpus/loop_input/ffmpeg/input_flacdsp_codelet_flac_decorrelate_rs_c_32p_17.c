#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int len = 32768;
int shift = 2;
int i;

int32_t **in;
int32_t **samples;

void init_vars() {
    // Allocate two input arrays
    in = (int32_t**)calloc(2, sizeof(int32_t*));
    in[0] = (int32_t*)calloc(len, sizeof(int32_t));
    in[1] = (int32_t*)calloc(len, sizeof(int32_t));

    // Allocate two sample output arrays
    samples = (int32_t**)calloc(2, sizeof(int32_t*));
    samples[0] = (int32_t*)calloc(len, sizeof(int32_t));
    samples[1] = (int32_t*)calloc(len, sizeof(int32_t));

    // Initialize input data to non-zero values for meaningful computation
    for (int idx = 0; idx < len; idx++) {
        in[0][idx] = rand() & 0xFFFFF;
        in[1][idx] = rand() & 0xFFFFF;
    }
}