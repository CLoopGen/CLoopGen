#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int len = 1048576; // ~2^20 elements, suitable for ~0.01 sec runtime
int shift = 2;
int16_t *samples;
int32_t **in;
int i;

void init_vars() {
    // Allocate samples: 2 output values per iteration
    samples = (int16_t*)calloc(len * 2, sizeof(int16_t));
    if (!samples) exit(1);

    // Allocate two rows for in[0] and in[1]
    in = (int32_t**)calloc(2, sizeof(int32_t*));
    if (!in) exit(1);

    in[0] = (int32_t*)calloc(len, sizeof(int32_t));
    in[1] = (int32_t*)calloc(len, sizeof(int32_t));
    if (!in[0] || !in[1]) exit(1);

    // Initialize input data with non-zero test pattern
    for (i = 0; i < len; i++) {
        in[0][i] = i + 1;
        in[1][i] = (i % 3) ? 1 : 0;
    }
}