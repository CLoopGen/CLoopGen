#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE_MB 64
#define TOTAL_BYTES (DATA_SIZE_MB * 1024ULL * 1024)

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
uint32_t loop_cnt;

static uint8_t src_data[TOTAL_BYTES] __attribute__((aligned(32)));
static uint8_t dst_data[TOTAL_BYTES] __attribute__((aligned(32)));

void init_vars() {
    const uint64_t bytes_per_row = 64;
    src_stride = (int32_t)bytes_per_row;
    dst_stride = (int32_t)bytes_per_row;

    height = (int32_t)((TOTAL_BYTES / bytes_per_row) & ~3ULL);

    src = src_data;
    dst = dst_data;

    for (size_t i = 0; i < TOTAL_BYTES; i++) {
        src_data[i] = (uint8_t)(i & 0xFF);
        dst_data[i] = 0;
    }

    loop_cnt = 0;
}