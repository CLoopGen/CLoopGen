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

static uint8_t *src_buffer;
static uint8_t *ref_buffer;

void init_vars() {
    const int32_t data_size = 1 << 20; // 1MB of data per buffer
    src_buffer = aligned_alloc(64, data_size);
    ref_buffer = aligned_alloc(64, data_size);

    if (!src_buffer || !ref_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < data_size; ++i) {
        src_buffer[i] = rand() % 256;
        ref_buffer[i] = rand() % 256;
    }

    src_stride = 1024;
    ref_stride = 1024;
    height = 1024;

    src = src_buffer;
    ref = ref_buffer;
}