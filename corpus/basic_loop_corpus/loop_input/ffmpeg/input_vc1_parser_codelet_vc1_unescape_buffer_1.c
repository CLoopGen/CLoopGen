#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int size;
uint8_t *dst;
int dsize;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    size = 64 * 1024 * 1024; // 64 MB data size for ~0.01 sec on modern CPU
    src_buffer = (uint8_t*)malloc(size);
    dst_buffer = (uint8_t*)malloc(size);
    if (!src_buffer || !dst_buffer) {
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }
    src = src_buffer;
    dst = dst_buffer;
    dsize = 0;
}