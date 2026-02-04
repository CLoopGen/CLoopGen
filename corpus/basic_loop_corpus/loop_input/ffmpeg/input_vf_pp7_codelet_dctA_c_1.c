#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *dst;
uint8_t *src;
int stride;
int i;

#define DATA_SIZE (64 * 1024 * 1024)  // ~64MB to target ~0.01 sec runtime

static uint8_t src_data[DATA_SIZE];
static int16_t dst_data[DATA_SIZE / 2];  // Rough estimate for dst size

void init_vars() {
    stride = 1;
    src = src_data;
    dst = dst_data;

    // Initialize src with non-zero values to ensure meaningful computation
    for (size_t idx = 0; idx < DATA_SIZE; idx++) {
        src_data[idx] = (uint8_t)(idx % 251);
    }

    // Initialize dst to zero to avoid garbage data
    for (size_t idx = 0; idx < DATA_SIZE / 2; idx++) {
        dst_data[idx] = 0;
    }
}