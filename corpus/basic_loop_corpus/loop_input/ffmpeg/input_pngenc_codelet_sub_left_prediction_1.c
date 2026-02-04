#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src1;
uint8_t *src2;
int x;
int unaligned_w;

static uint8_t *buf_dst;
static uint8_t *buf_src1;
static uint8_t *buf_src2;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec on modern CPU
    unaligned_w = (int)data_size;

    buf_dst = aligned_alloc(32, data_size);
    buf_src1 = aligned_alloc(32, data_size);
    buf_src2 = aligned_alloc(32, data_size);

    dst = buf_dst;
    src1 = buf_src1;
    src2 = buf_src2;

    for (size_t i = 0; i < data_size; i++) {
        buf_src1[i] = (uint8_t)(i & 0xFF);
        buf_src2[i] = (uint8_t)((i + 1) & 0xFF);
    }
}