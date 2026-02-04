#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS ((DATA_SIZE_MB * 1024 * 1024) / sizeof(int16_t))

int16_t *dst;
int16_t *vector;
int length;
int bits;
int i;

void init_vars() {
    length = TOTAL_ELEMENTS;
    bits = 5; 
    i = 0;

    dst = aligned_alloc(32, length * sizeof(int16_t));
    vector = aligned_alloc(32, length * sizeof(int16_t));

    if (!dst || !vector) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < length; idx++) {
        vector[idx] = (int16_t)(idx % 32768);
        dst[idx] = 0;
    }
}