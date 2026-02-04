#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 1024;
int width = 64;
int x;
int y;

uint16_t *src;
int16_t *dst;
ptrdiff_t srcstride = 64;
int8_t *filter;

void init_vars() {
    src = (uint16_t*)aligned_alloc(64, sizeof(uint16_t) * (height + 7) * srcstride);
    dst = (int16_t*)aligned_alloc(64, sizeof(int16_t) * height * 64);
    filter = (int8_t*)aligned_alloc(64, sizeof(int8_t) * 8);

    for (int i = 0; i < 8; i++) {
        filter[i] = (int8_t)(i == 3 ? 128 : 0); // Identity-like filter centered at index 3
    }

    size_t total_src_size = (height + 7) * srcstride;
    for (size_t i = 0; i < total_src_size; i++) {
        src[i] = rand() & 0xFFFF;
    }
}

// Ensure definitions are available for extern references
uint16_t *src;
int16_t *dst;
int8_t *filter;
int height;
int width;
int x;
int y;
ptrdiff_t srcstride;