#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int len = 64 << 10; // 64k iterations to target ~0.01s runtime
int shift = 2;
int32_t *samples;
int i;

int32_t **in;

void init_vars() {
    // Allocate space for two rows of int32_t arrays
    in = (int32_t**)calloc(2, sizeof(int32_t*));
    in[0] = (int32_t*)calloc(len, sizeof(int32_t));
    in[1] = (int32_t*)calloc(len, sizeof(int32_t));

    // Initialize input data with non-zero test values
    for (i = 0; i < len; i++) {
        in[0][i] = i + 1;
        in[1][i] = (i % 3) + 1;
    }

    // Allocate samples: 2 outputs per iteration
    samples = (int32_t*)calloc(len * 2, sizeof(int32_t));
}