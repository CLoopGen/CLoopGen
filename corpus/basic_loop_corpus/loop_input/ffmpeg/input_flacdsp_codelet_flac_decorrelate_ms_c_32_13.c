#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int len = 1 << 20; // Approximately 1M iterations for ~0.01 sec runtime
int shift = 2;
int32_t *samples;
int i;

int32_t **in;

void init_vars() {
    // Allocate space for two rows of int32_t data
    in = (int32_t**)calloc(2, sizeof(int32_t*));
    if (!in) exit(1);

    in[0] = (int32_t*)calloc(len, sizeof(int32_t));
    in[1] = (int32_t*)calloc(len, sizeof(int32_t));
    if (!in[0] || !in[1]) exit(1);

    // Initialize input arrays with non-zero test data
    for (i = 0; i < len; i++) {
        in[0][i] = i + 1;
        in[1][i] = (i & 1) ? -i : i;
    }

    // Allocate output buffer: 2 int32_t values per loop iteration
    samples = (int32_t*)calloc(len * 2, sizeof(int32_t));
    if (!samples) exit(1);
}