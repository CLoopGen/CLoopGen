#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *tmp;
uint8_t *src;
int tmpStride;
int srcStride;
int h;
int pad;
int i;

#define DATA_SIZE (64 * 1024 * 1024)  // ~64MB of source data
#define HEIGHT 4096

void init_vars() {
    pad = 10;
    h = HEIGHT;
    srcStride = 16384;  // Wide stride to prevent overlap
    tmpStride = 2048;
    
    src = (uint8_t*)aligned_alloc(64, (srcStride * h) + 10);
    tmp = (int16_t*)aligned_alloc(64, (tmpStride * h) * sizeof(int16_t));
    
    if (!src || !tmp) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    for (int i = 0; i < (srcStride * h) + 10; i++) {
        src[i] = rand() % 255;
    }
    
    for (int i = 0; i < tmpStride * h; i++) {
        tmp[i] = 0;
    }
}