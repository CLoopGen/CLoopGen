#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int32_t src_stride;
int16_t *dst;
int32_t dst_stride;
int32_t height;
uint32_t loop_cnt;

static uint8_t src_data[131072];
static int16_t dst_data[65536];

void init_vars() {
    src = src_data;
    src_stride = 4;
    dst = dst_data;
    dst_stride = 2;
    height = 32768;
}

// The function 'loop' is defined externally and will be linked in.