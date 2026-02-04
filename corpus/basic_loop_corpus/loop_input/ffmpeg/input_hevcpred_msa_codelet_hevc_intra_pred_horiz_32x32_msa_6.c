#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src_left;
uint8_t *dst;
int32_t stride;
uint32_t row;
uint8_t inp0;
uint8_t inp1;
uint8_t inp2;
uint8_t inp3;

static uint8_t *src_left_data;
static uint8_t *dst_data;
static size_t total_size = 64 * 1024 * 1024; // 64 MB for sustained access

void init_vars() {
    src_left_data = (uint8_t*)aligned_alloc(32, total_size);
    dst_data = (uint8_t*)aligned_alloc(32, total_size);

    if (!src_left_data || !dst_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_size; ++i) {
        src_left_data[i] = (uint8_t)(i & 0xFF);
        dst_data[i] = 0;
    }

    src_left = src_left_data;
    dst = dst_data;
    stride = 16;
    row = 0;
    inp0 = 0;
    inp1 = 0;
    inp2 = 0;
    inp3 = 0;
}