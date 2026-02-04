#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
int width;
uint8_t mask;
uint8_t *src;
int i;

void init_vars() {
    width = 1 << 20;
    uint32_t total_size = width * 2;
    dst = (uint8_t*)aligned_alloc(32, total_size);
    src = (uint8_t*)aligned_alloc(32, total_size);
    mask = 0xFF;
    for (uint32_t idx = 0; idx < total_size; idx++) {
        src[idx] = (uint8_t)(idx & 0xFF);
        dst[idx] = 0;
    }
}