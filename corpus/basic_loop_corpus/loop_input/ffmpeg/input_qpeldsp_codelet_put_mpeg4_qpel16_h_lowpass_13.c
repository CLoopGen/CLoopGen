#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * 1024 * 1024)

uint8_t *dst;
uint8_t *src;
int dstStride;
int srcStride;
int h;
uint8_t *cm;
int i;

static uint8_t *internal_dst_buffer;
static uint8_t *internal_src_buffer;
static uint8_t internal_cm_buffer[256];

void init_vars() {
    const int width = 17;
    const int row_size = width * sizeof(uint8_t);
    const int rows = TOTAL_ELEMENTS / row_size;
    
    internal_dst_buffer = aligned_alloc(32, rows * row_size);
    internal_src_buffer = aligned_alloc(32, rows * row_size);

    if (!internal_dst_buffer || !internal_src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < rows * width; i++) {
        internal_src_buffer[i] = rand() % 256;
        internal_dst_buffer[i] = 0;
    }

    for (int i = 0; i < 256; i++) {
        internal_cm_buffer[i] = i;
    }

    dstStride = width;
    srcStride = width;
    h = rows;

    dst = internal_dst_buffer;
    src = internal_src_buffer;
    cm = internal_cm_buffer;
}