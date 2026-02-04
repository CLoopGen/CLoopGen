#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define DATA_SIZE (64 * 1024 * 1024)

uint8_t *dst;
uint8_t *src;
ptrdiff_t dstStride = 1;
ptrdiff_t srcStride = 1;
int w;
uint8_t *cm;
int i;

uint8_t *src_base;
uint8_t *dst_base;
uint8_t *cm_base;

void init_vars() {
    src_base = aligned_alloc(32, DATA_SIZE + 20);
    dst_base = aligned_alloc(32, DATA_SIZE + 10);
    cm_base = aligned_alloc(32, 256);

    if (!src_base || !dst_base || !cm_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < DATA_SIZE + 20; i++) {
        src_base[i] = rand() & 0xFF;
    }
    for (size_t i = 0; i < DATA_SIZE + 10; i++) {
        dst_base[i] = rand() & 0xFF;
    }
    for (int i = 0; i < 256; i++) {
        cm_base[i] = rand() & 0x7F;
    }

    src = src_base + 10;
    dst = dst_base + 4;
    w = DATA_SIZE / 2;

    cm = cm_base;
}

void cleanup() {
    free(src_base);
    free(dst_base);
    free(cm_base);
}