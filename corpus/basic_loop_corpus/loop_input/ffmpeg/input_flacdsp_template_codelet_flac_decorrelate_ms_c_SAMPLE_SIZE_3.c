#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int len = 1 << 20; // Approximately 1 million iterations for ~0.01 sec runtime
int shift = 2;
int32_t **in;
int16_t *samples;
int i;

void init_vars() {
    // Allocate two rows of int32_t arrays, each of length 'len'
    int32_t *row0 = (int32_t*)calloc(len, sizeof(int32_t));
    int32_t *row1 = (int32_t*)calloc(len, sizeof(int32_t));

    // Initialize with non-zero test data to allow verification if needed
    for (int j = 0; j < len; j++) {
        row0[j] = (int32_t)(j * 2);
        row1[j] = (int32_t)(j);
    }

    // Allocate double pointer array for in[2]
    in = (int32_t**)malloc(2 * sizeof(int32_t*));
    in[0] = row0;
    in[1] = row1;

    // Allocate samples: 2 int16_t values per loop iteration
    samples = (int16_t*)malloc(2 * len * sizeof(int16_t));
}