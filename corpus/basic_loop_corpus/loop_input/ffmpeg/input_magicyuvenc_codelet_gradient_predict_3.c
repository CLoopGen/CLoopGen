#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint8_t *dst;
ptrdiff_t stride;
int width;
int height;
int left;
int top;
int lefttop;
int i;
int j;

#define DATA_SIZE_MB 64

void init_vars() {
    width = 4096;
    height = (DATA_SIZE_MB * 1024 * 1024) / width;
    while (height * width < DATA_SIZE_MB * 1024 * 1024) {
        height++;
    }
    
    stride = width;
    
    src = aligned_alloc(32, height * stride);
    dst = aligned_alloc(32, height * width);
    
    for (int idx = 0; idx < height * stride; idx++) {
        src[idx] = rand() & 0xFF;
    }
    
    left = 0;
    top = 0;
    lefttop = 0;
    i = 0;
    j = 0;
}