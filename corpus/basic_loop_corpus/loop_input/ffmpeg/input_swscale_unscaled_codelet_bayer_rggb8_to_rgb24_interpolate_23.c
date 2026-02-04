#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define DATA_SIZE_MB 64
#define TOTAL_SIZE (DATA_SIZE_MB * 1024ULL * 1024)

uint8_t *src_base;
uint8_t *dst_base;
uint8_t *src;
uint8_t *dst;
int src_stride;
int dst_stride;
int width;
int i;

void init_vars() {
    const int aligned_width = 1920;
    const int aligned_height = 1080;
    
    width = aligned_width;
    src_stride = aligned_width + 8;
    dst_stride = aligned_width * 3 / 2 + 16;

    size_t src_size = (size_t)src_stride * (aligned_height + 4);
    size_t dst_size = (size_t)dst_stride * (aligned_height / 2 + 4);

    src_base = aligned_alloc(32, src_size);
    dst_base = aligned_alloc(32, dst_size);

    if (!src_base || !dst_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    memset(src_base, 0, src_size);
    memset(dst_base, 0, dst_size);

    for (int y = 0; y < (int)src_size; y++) {
        src_base[y] = rand() & 0xFF;
    }

    src = src_base + (2 * src_stride + 2);
    dst = dst_base + (0 * dst_stride);
}