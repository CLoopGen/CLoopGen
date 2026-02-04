#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * 1024 * 1024 / sizeof(int16_t))
#define WIDTH 8

uint8_t *dst;
ptrdiff_t dstStride;
int16_t *tmp;
int w;
uint8_t *cm;
int i;

void init_vars() {
    const int tmp_offset = 12; // Need tmp[-2] to tmp[10], so at least 13 elements before main access
    const int tmp_total = TOTAL_ELEMENTS + tmp_offset * 8;
    
    // Allocate cm with size 1024 to safely index within [0, 1023] after shift
    cm = aligned_alloc(32, 1024 * sizeof(uint8_t));
    for (int idx = 0; idx < 1024; idx++) {
        cm[idx] = (uint8_t)(idx & 0xFF);
    }

    // Allocate tmp with sufficient padding
    tmp = aligned_alloc(32, tmp_total * sizeof(int16_t));
    for (int idx = 0; idx < tmp_total; idx++) {
        tmp[idx] = (int16_t)(rand() % 512 - 256);
    }

    // Allocate dst buffer: w columns and 8 rows with stride spacing
    w = TOTAL_ELEMENTS / 8;
    dstStride = 8 * sizeof(int16_t); // Stride in bytes, assume row-major layout

    dst = aligned_alloc(32, w * dstStride * 8);
    memset(dst, 0, w * dstStride * 8);

    i = 0;
}

// Definitions of external variables
uint8_t *dst;
ptrdiff_t dstStride;
int16_t *tmp;
int w;
uint8_t *cm;
int i;