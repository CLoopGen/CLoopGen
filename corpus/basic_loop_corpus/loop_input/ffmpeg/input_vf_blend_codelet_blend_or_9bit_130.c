#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t top_linesize;
ptrdiff_t bottom_linesize;
ptrdiff_t dst_linesize;
ptrdiff_t width;
ptrdiff_t height;
uint16_t *top;
uint16_t *bottom;
uint16_t *dst;
double opacity;
int i;
int j;

void init_vars() {
    width = 2048;
    height = 128;
    opacity = 0.75;

    top_linesize = width * sizeof(uint16_t);
    bottom_linesize = width * sizeof(uint16_t);
    dst_linesize = width * sizeof(uint16_t);

    top = aligned_alloc(32, height * top_linesize);
    bottom = aligned_alloc(32, height * bottom_linesize);
    dst = aligned_alloc(32, height * dst_linesize);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            top[i * (top_linesize / sizeof(uint16_t)) + j] = rand() % 65536;
            bottom[i * (bottom_linesize / sizeof(uint16_t)) + j] = rand() % 65536;
        }
    }
}