#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define DATA_SIZE_MB 64
#define TOTAL_SIZE (DATA_SIZE_MB * 1024ULL * 1024ULL)

uint8_t *src_base;
uint8_t *dst_base;
uint8_t *src;
uint8_t *dst;
int src_stride;
int dst_stride;
int width;
int i;

void init_vars() {
    const int padding = 4;
    src_stride = width + 2 * padding;
    dst_stride = (width - 2) / 2 * 3;

    size_t src_size = src_stride * (6);
    size_t dst_size = dst_stride * (2);

    src_base = aligned_alloc(32, src_size);
    dst_base = aligned_alloc(32, dst_size);

    if (!src_base || !dst_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    memset(src_base, 0, src_size);
    memset(dst_base, 0, dst_size);

    for (int y = 0; y < 6; y++) {
        for (int x = 0; x < src_stride; x++) {
            ptrdiff_t idx = y * src_stride + x;
            src_base[idx] = rand() % 256;
        }
    }

    src = src_base + padding + 1 * src_stride + 1;
    dst = dst_base;
}

static void __attribute__((constructor)) initialize() {
    width = (TOTAL_SIZE / DATA_SIZE_MB) * 8;
    if (width < 10) width = 1000;
    while ((width - 2) % 2 != 0) width++;
    init_vars();
}