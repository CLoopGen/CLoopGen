#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int32_t src_stride;
uint8_t *ref;
int32_t ref_stride;
int32_t height;
int32_t ht_cnt;

static uint8_t *src_data;
static uint8_t *ref_data;

void init_vars() {
    const size_t total_data_size = 64 * 1024 * 1024; // ~64 MB for sufficient runtime (~0.01s on modern CPU)

    src_stride = 1024;
    ref_stride = 1024;
    height = 8192;

    size_t src_total = (size_t)(height * src_stride);
    size_t ref_total = (size_t)((5 + 3) * (height >> 3) + 1) * ref_stride;

    src_data = calloc(src_total, sizeof(uint8_t));
    ref_data = calloc(ref_total, sizeof(uint8_t));

    if (!src_data || !ref_data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    src = src_data;
    ref = ref_data;

    ht_cnt = height >> 3;

    for (size_t i = 0; i < src_total; i++) {
        src_data[i] = rand() & 0xFF;
    }
    for (size_t i = 0; i < ref_total; i++) {
        ref_data[i] = rand() & 0xFF;
    }
}