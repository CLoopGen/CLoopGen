#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *coeffs;
uint8_t *dst;
int32_t stride;
uint8_t loop_cnt;
uint8_t *temp_dst;

static int16_t coeffs_data[64 * 15]; // Enough for 15 iterations of coeffs += 64
static uint8_t dst_data[256 * 1024]; // ~256KB for dst and temp_dst usage
static uint8_t temp_dst_data[256 * 1024];

void init_vars() {
    stride = 32; // Moderate stride to allow multiple accesses without overflow

    coeffs = coeffs_data;
    dst = dst_data;
    temp_dst = temp_dst_data;

    for (size_t i = 0; i < sizeof(coeffs_data) / sizeof(int16_t); ++i) {
        coeffs_data[i] = (int16_t)(i % 32768);
    }

    for (size_t i = 0; i < sizeof(dst_data); ++i) {
        dst_data[i] = (uint8_t)(i % 256);
    }

    for (size_t i = 0; i < sizeof(temp_dst_data); ++i) {
        temp_dst_data[i] = (uint8_t)(i % 256);
    }
}