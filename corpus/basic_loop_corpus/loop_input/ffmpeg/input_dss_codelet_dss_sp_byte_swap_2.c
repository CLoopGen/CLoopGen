#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
int i;

static uint8_t *dst_buffer;
static uint8_t *src_buffer;
static size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime

void init_vars() {
    dst_buffer = calloc(data_size, sizeof(uint8_t));
    src_buffer = calloc(data_size, sizeof(uint8_t));

    if (!dst_buffer || !src_buffer) {
        exit(1);
    }

    dst = dst_buffer;
    src = src_buffer;

    for (size_t idx = 0; idx < data_size; ++idx) {
        src_buffer[idx] = (uint8_t)(idx & 0xFF);
    }
}