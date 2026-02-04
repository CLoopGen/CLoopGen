#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint8_t *dst;
int width;
int i;
uint8_t prev;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    width = 64 * 1024 * 1024; // 64 million elements for ~0.01 sec runtime

    src_buffer = (uint8_t*)aligned_alloc(32, width * sizeof(uint8_t));
    dst_buffer = (uint8_t*)aligned_alloc(32, width * sizeof(uint8_t));

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    for (int j = 0; j < width; j++) {
        src_buffer[j] = rand() & 0xFF;
    }
    prev = 0x5A;

    src = src_buffer;
    dst = dst_buffer;
}