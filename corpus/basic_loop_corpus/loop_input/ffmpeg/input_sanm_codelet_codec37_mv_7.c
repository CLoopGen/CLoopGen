#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
int height;
int stride;
int pos;
int i;
int j;

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    height = 64;
    stride = 64;
    pos = 0;

    size_t total_size = height * stride;
    dst_buffer = (uint8_t*)calloc(total_size, sizeof(uint8_t));
    src_buffer = (uint8_t*)calloc(total_size, sizeof(uint8_t));

    for (size_t idx = 0; idx < total_size; idx++) {
        src_buffer[idx] = (uint8_t)(idx & 0xFF);
    }

    dst = dst_buffer;
    src = src_buffer;
}