#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (128 * 1024 * 1024)

uint8_t *src;
int src_stride;
uint8_t *dst;
int dst_stride;
int width;
int i;

static uint8_t src_data[DATA_SIZE];
static uint8_t dst_data[DATA_SIZE];

void init_vars() {
    const int block_height = 2;
    const int block_width = 3;
    const int num_blocks = (DATA_SIZE / 2) / (block_height * block_width); // approximate fit

    width = num_blocks * 2; 

    src_stride = 2;
    dst_stride = 3;

    src = src_data;
    dst = dst_data;

    for (int idx = 0; idx < DATA_SIZE; ++idx) {
        src_data[idx] = rand() & 0xFF;
    }
    memset(dst_data, 0, DATA_SIZE);
}