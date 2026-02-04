#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *flags;
int i;
int32_t *src;
int32_t *dst;
int t0;
int t1;
int t2;
int t3;
int t4;

static uint8_t flags_buf[4];
static int32_t src_buf[16 * 256 * 1024]; // 16 elements per block, scaled for ~0.01s runtime
static int32_t dst_buf[16 * 256 * 1024];

void init_vars() {
    flags = flags_buf;
    src = src_buf;
    dst = dst_buf;

    for (int j = 0; j < 4; j++) {
        flags[j] = 1;
    }

    size_t total_elements = 16 * 256 * 1024;
    for (size_t j = 0; j < total_elements; j++) {
        src_buf[j] = (int32_t)(j % 1000);
        dst_buf[j] = 0;
    }
}