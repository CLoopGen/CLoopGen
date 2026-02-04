#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *coeffs;
uint8_t *dst;
int32_t stride;
uint8_t loop_cnt;
uint8_t *temp_dst;

static int16_t *coeffs_buffer;
static uint8_t *dst_buffer;
static uint8_t *temp_dst_buffer;

void init_vars() {
    size_t data_size = 1 << 20; // ~1MB of input data
    stride = 64;

    coeffs_buffer = aligned_alloc(32, data_size * sizeof(int16_t));
    dst_buffer = aligned_alloc(32, data_size * sizeof(uint8_t));
    temp_dst_buffer = aligned_alloc(32, data_size * sizeof(uint8_t));

    coeffs = coeffs_buffer;
    dst = dst_buffer;
    temp_dst = temp_dst_buffer;

    for (size_t i = 0; i < data_size; i++) {
        coeffs_buffer[i] = (int16_t)(i & 0x7FFF);
        dst_buffer[i] = (uint8_t)(i & 0xFF);
        temp_dst_buffer[i] = (uint8_t)((i + 32) & 0xFF);
    }

    loop_cnt = 0;
}