#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

uint8_t *dst;
uint8_t *src1;
uint8_t *src2;
intptr_t w;
long i;

static size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec estimate

void init_vars() {
    dst = aligned_alloc(64, data_size);
    src1 = aligned_alloc(64, data_size);
    src2 = aligned_alloc(64, data_size);

    if (!dst || !src1 || !src2) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize arrays with non-zero predictable patterns
    for (size_t j = 0; j < data_size; j++) {
        src1[j] = (uint8_t)(j & 0xFF);
        src2[j] = (uint8_t)((j >> 4) & 0xFF);
    }
    memset(dst, 0, data_size);

    // Set loop bound: ensure i <= w - sizeof(long), so w = data_size
    w = (intptr_t)data_size;
}