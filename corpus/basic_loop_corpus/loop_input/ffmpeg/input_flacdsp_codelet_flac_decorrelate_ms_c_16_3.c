#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int len = 65536;
int shift = 2;
int i;

int32_t **in;
int16_t *samples;

void init_vars() {
    // Allocate two rows for in
    in = (int32_t**)calloc(2, sizeof(int32_t*));
    if (!in) exit(1);

    in[0] = (int32_t*)calloc(len, sizeof(int32_t));
    in[1] = (int32_t*)calloc(len, sizeof(int32_t));
    if (!in[0] || !in[1]) exit(1);

    // Initialize input arrays with non-zero test data
    for (int idx = 0; idx < len; idx++) {
        in[0][idx] = idx * 3;
        in[1][idx] = idx * 2 + 1;
    }

    // Allocate samples: 2 int16_t per iteration
    samples = (int16_t*)calloc(len * 2, sizeof(int16_t));
    if (!samples) exit(1);
}