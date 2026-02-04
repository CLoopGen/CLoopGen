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
const int data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec on modern CPU

void init_vars() {
    src_buffer = (uint8_t*)malloc(data_size);
    dst_buffer = (uint8_t*)malloc(data_size);
    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    for (int i = 0; i < data_size; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }

    src = src_buffer;
    dst = dst_buffer;
    size = data_size;
    dsize = 0;
}