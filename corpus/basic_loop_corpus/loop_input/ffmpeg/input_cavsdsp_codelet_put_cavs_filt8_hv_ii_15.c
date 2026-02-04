#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
ptrdiff_t dstStride;
int16_t *tmp;
int w;
uint8_t *cm;
int i;

static uint8_t *dst_storage;
static int16_t *tmp_storage;
static uint8_t *cm_storage;

void init_vars() {
    const size_t data_size = 16 * 1024 * 1024; // 16 MB of data for sufficient runtime

    // cm is an index table, typically 256 bytes (for values 0-255 after clamping)
    cm_storage = calloc(256, sizeof(uint8_t));
    for (int j = 0; j < 256; j++) {
        cm_storage[j] = (uint8_t)j;
    }
    cm = cm_storage;

    // tmp needs to hold at least from index -2*8 to 10*8 + w, so total span is 13*8 + w
    // We allocate extra space for negative indexing and sliding window
    const size_t tmp_span_per_iter = 13 * 8; // from -2 to +10 inclusive in steps of 8
    w = (data_size / sizeof(int16_t)) / tmp_span_per_iter;
    if (w == 0) w = 1;

    const size_t tmp_total_elements = tmp_span_per_iter + w;
    tmp_storage = calloc(tmp_total_elements, sizeof(int16_t));
    for (size_t j = 0; j < tmp_total_elements; j++) {
        tmp_storage[j] = (int16_t)(rand() % 512 - 256);
    }
    // Point tmp to the center so that [-2*8] is valid
    tmp = tmp_storage + 2 * 8;

    // dst is written with 8 rows, each with stride dstStride
    dstStride = 1;
    size_t dst_size = 8 * dstStride * w;
    dst_storage = calloc(dst_size, sizeof(uint8_t));
    dst = dst_storage;

    i = 0;
}