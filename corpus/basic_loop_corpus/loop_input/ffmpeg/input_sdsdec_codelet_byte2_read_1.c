#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint32_t *dst;
int i;

static uint8_t src_buffer[134217728]; // ~128MB to target ~0.01 sec runtime
static uint32_t dst_buffer[67108864];  // dst size: src_size / 2 * sizeof(uint8_t->uint32_t mapping)

void init_vars() {
    src = src_buffer;
    dst = dst_buffer;
    for (int j = 0; j < 134217728; ++j) {
        src[j] = (uint8_t)(j & 0xFF);
    }
    for (int j = 0; j < 67108864; ++j) {
        dst[j] = 0;
    }
}