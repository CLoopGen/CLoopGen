#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
ptrdiff_t srcstride;
int h;
uint8_t *filter;
uint8_t *cm;
int x;
int y;
uint8_t *tmp;

void init_vars() {
    h = 1000;
    srcstride = 64;
    int width = 10;
    int total_src_size = (h + 6 - 1) * srcstride;
    src = (uint8_t*)aligned_alloc(32, total_src_size);
    tmp = (uint8_t*)aligned_alloc(32, (h + 6 - 1) * 4);
    filter = (uint8_t*)aligned_alloc(32, 5);
    cm = (uint8_t*)aligned_alloc(32, 256);

    for (int i = 0; i < 5; i++)
        filter[i] = 16;
    for (int i = 0; i < 256; i++)
        cm[i] = i;
    for (int i = 0; i < total_src_size; i++)
        src[i] = rand() % 256;
}