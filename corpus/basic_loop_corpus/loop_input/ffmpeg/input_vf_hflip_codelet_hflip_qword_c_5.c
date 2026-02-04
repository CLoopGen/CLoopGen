#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w;
uint64_t *src;
uint64_t *dst;
int j;

void init_vars() {
    w = 1048576; // 1MB of uint64_t data: 1048576 elements * 8 bytes = 8MB total

    src = (uint64_t*)malloc(w * sizeof(uint64_t));
    dst = (uint64_t*)malloc(w * sizeof(uint64_t));

    for (int i = 0; i < w; i++) {
        src[i] = (uint64_t)(0xDEADBEEFCAFEULL & 0xFFFFFFFFFFFFULL) + i;
    }

    j = 0;
}