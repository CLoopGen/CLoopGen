#include <stdint.h>
#include <stdlib.h>

uint8_t *dst;
int width;
int height;
int linesize;
int x;
int y;
int i;
int size;
uint32_t pixel;

void init_vars() {
    width = 1920;
    height = 1080;
    linesize = width * 4;
    x = 0;
    y = 0;
    pixel = 0xFFAA5500;
    size = (width * height) / 2;

    dst = aligned_alloc(32, (size_t)linesize * height);
    if (!dst) exit(1);
}