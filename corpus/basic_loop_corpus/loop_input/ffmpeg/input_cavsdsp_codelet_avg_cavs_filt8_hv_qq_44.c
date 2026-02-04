#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *dst;
uint8_t *src2;
ptrdiff_t dstStride;
ptrdiff_t srcStride;
int16_t *tmp;
int w;
uint8_t *cm;
int i;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * (1 << 20) / sizeof(int16_t))
#define TMP_OFFSET 10
#define MAX_TMP_ACCESS (TMP_OFFSET + 8 * 8)
#define STRIDE 1

static uint8_t *internal_dst_buffer;
static uint8_t *internal_src2_buffer;
static int16_t *internal_tmp_buffer;
static uint8_t *internal_cm_buffer;

void init_vars() {
    const size_t total_tmp_size = TOTAL_ELEMENTS + MAX_TMP_ACCESS;
    
    internal_dst_buffer = (uint8_t *)aligned_alloc(32, TOTAL_ELEMENTS * STRIDE * sizeof(uint8_t));
    internal_src2_buffer = (uint8_t *)aligned_alloc(32, TOTAL_ELEMENTS * STRIDE * sizeof(uint8_t));
    internal_tmp_buffer = (int16_t *)aligned_alloc(32, total_tmp_size * sizeof(int16_t));
    internal_cm_buffer = (uint8_t *)aligned_alloc(32, 1024 * sizeof(uint8_t));

    if (!internal_dst_buffer || !internal_src2_buffer || !internal_tmp_buffer || !internal_cm_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < TOTAL_ELEMENTS * STRIDE; ++idx) {
        internal_dst_buffer[idx] = rand() & 0xFF;
        internal_src2_buffer[idx] = rand() & 0xFF;
    }

    for (size_t idx = 0; idx < total_tmp_size; ++idx) {
        internal_tmp_buffer[idx] = (rand() % 255) - 128;
    }

    for (int idx = 0; idx < 1024; ++idx) {
        internal_cm_buffer[idx] = rand() & 0x7F;
    }

    dst = internal_dst_buffer;
    src2 = internal_src2_buffer;
    tmp = internal_tmp_buffer + TMP_OFFSET;
    dstStride = STRIDE;
    srcStride = STRIDE;
    cm = internal_cm_buffer;
    w = TOTAL_ELEMENTS;
    i = 0;
}