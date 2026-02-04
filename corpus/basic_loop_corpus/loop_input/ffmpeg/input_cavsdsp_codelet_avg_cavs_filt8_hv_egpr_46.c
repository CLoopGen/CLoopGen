#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

uint8_t *src1;
ptrdiff_t srcStride;
int16_t *tmp;
int h;
int i;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB to ensure measurable runtime
#define TMP_SIZE (DATA_SIZE / 8 * 8) // tmp array sized for iterations

static uint8_t src1_data[DATA_SIZE];
static int16_t tmp_data[TMP_SIZE];

void init_vars() {
    // Initialize global variables
    src1 = src1_data;
    tmp = tmp_data;
    srcStride = 8; // stride of 8 bytes per iteration
    h = (DATA_SIZE - 10) / srcStride; // ensure we don't go out of bounds in the loop
    i = 0;

    // Initialize src1_data with non-zero values to avoid all-zero computations
    for (size_t idx = 0; idx < DATA_SIZE; ++idx) {
        src1_data[idx] = (uint8_t)(idx % 251);
    }

    // Zero-initialize tmp_data
    memset(tmp_data, 0, sizeof(tmp_data));
}