#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int len = 65536;
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

    // Initialize input data with non-zero values for meaningful computation
    for (int idx = 0; idx < len; idx++) {
        in[0][idx] = (int32_t)(idx % 1000);
        in[1][idx] = (int32_t)((idx + 500) % 1000);
    }
}