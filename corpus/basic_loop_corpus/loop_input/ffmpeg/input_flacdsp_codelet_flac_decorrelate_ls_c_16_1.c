#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t **in;
int len;
int shift;
int16_t *samples;
int i;

void init_vars() {
    len = 65536;          // ~131KB of input (65536 * 2 * 4 bytes) -> fits in target range
    shift = 1;            // reasonable shift value to preserve data after shifting
    i = 0;

    // Allocate two rows for in[2][len]
    in = (int32_t**)calloc(2, sizeof(int32_t*));
    in[0] = (int32_t*)calloc(len, sizeof(int32_t));
    in[1] = (int32_t*)calloc(len, sizeof(int32_t));

    // Initialize input data with non-zero test pattern
    for (int idx = 0; idx < len; idx++) {
        in[0][idx] = idx + 1;
        in[1][idx] = idx;
    }

    // Allocate output: each input pair produces two int16_t values => 2 * 2 * len bytes
    samples = (int16_t*)calloc(2 * len, sizeof(int16_t));
}