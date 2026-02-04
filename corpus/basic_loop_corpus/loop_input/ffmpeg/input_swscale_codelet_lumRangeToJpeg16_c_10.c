#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width;
int i;
int32_t *dst;

void init_vars() {
    width = 1 << 20;  // Approximately 4 million elements for ~0.01 sec runtime
    dst = (int32_t*)aligned_alloc(32, width * sizeof(int32_t));
    if (!dst) {
        exit(1);
    }
    for (int j = 0; j < width; j++) {
        dst[j] = rand() % 100000;
    }
}