#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *dst;
ptrdiff_t dstStride;
int16_t *tmp;
int w;
uint8_t *cm;
int i;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * 1024 * 1024)
#define TMP_EXTRA 11
#define DST_HEIGHT 8

void init_vars() {
    const size_t tmp_size = TOTAL_ELEMENTS + TMP_EXTRA * 8;
    const size_t dst_size = TOTAL_ELEMENTS * DST_HEIGHT;
    const size_t cm_size = 512;

    uint8_t *dst_data = aligned_alloc(32, dst_size * sizeof(uint8_t));
    int16_t *tmp_data = aligned_alloc(32, tmp_size * 8 * sizeof(int16_t));
    uint8_t *cm_data = aligned_alloc(32, cm_size * sizeof(uint8_t));

    if (!dst_data || !tmp_data || !cm_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < dst_size; idx++) {
        dst_data[idx] = rand() & 0xFF;
    }
    for (size_t idx = 0; idx < tmp_size * 8; idx++) {
        tmp_data[idx] = (rand() % 2047) - 1024;
    }
    for (size_t idx = 0; idx < cm_size; idx++) {
        cm_data[idx] = rand() & 0xFF;
    }

    dst = dst_data;
    dstStride = TOTAL_ELEMENTS;
    tmp = tmp_data + 2 * 8;
    cm = cm_data + 256;
    w = TOTAL_ELEMENTS;
}