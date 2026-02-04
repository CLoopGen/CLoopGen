#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *dst;
int *src;
int len;
int i;

void init_vars() {
    len = 64 * 1024 * 1024; // Approx. 256MB of data (64M elements * (4 bytes int + 4 bytes float))

    src = (int *)aligned_alloc(32, len * sizeof(int));
    dst = (float *)aligned_alloc(32, len * sizeof(float));

    if (!src || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < len; j++) {
        src[j] = rand() % 1000;
        dst[j] = 0.0F;
    }

    i = 0;
}