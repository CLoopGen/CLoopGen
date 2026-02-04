#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
uint8_t *iv;
int i;

static uint8_t *dst_buf;
static uint8_t *src_buf;
static uint8_t *iv_buf;

void init_vars() {
    size_t data_size = 128 * 1024 * 1024; // 128 MB for ~0.01 sec runtime on modern CPU

    dst_buf = aligned_alloc(32, data_size);
    src_buf = aligned_alloc(32, data_size);
    iv_buf  = aligned_alloc(32, data_size);

    if (!dst_buf || !src_buf || !iv_buf) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t j = 0; j < data_size; j++) {
        src_buf[j] = (uint8_t)(j & 0xFF);
        iv_buf[j]  = (uint8_t)((j ^ 0xAA) & 0xFF);
    }

    dst = dst_buf;
    src = src_buf;
    iv = iv_buf;
    i = 0;
}