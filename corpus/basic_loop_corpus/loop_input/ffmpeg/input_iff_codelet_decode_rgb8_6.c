#include <stdint.h>
#include <stdlib.h>

uint8_t *dst;
int width;
int height;
int linesize;
int x;
int y;
int i;
int length;
uint32_t pixel;

void init_vars() {
    width = 1920;
    height = 1080;
    linesize = width * sizeof(uint32_t);
    length = 1000000;
    pixel = 0xFFAABBCC;
    x = 0;
    y = 0;
    dst = aligned_alloc(32, (size_t)height * linesize);
}

__attribute__((destructor))
static void cleanup() {
    free(dst);
}