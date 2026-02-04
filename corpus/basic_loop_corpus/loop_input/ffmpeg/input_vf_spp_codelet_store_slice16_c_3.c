#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint16_t *dst;
int16_t *src;
int dst_linesize;
int src_linesize;
int width;
int height;
int log2_scale;
uint8_t dither[8][8];
int y;
int x;
unsigned int mask;

void init_vars() {
    width = 4096;
    height = 64;
    log2_scale = 3;
    mask = 0x80000000U;
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            dither[i][j] = (uint8_t)((i * 17 + j * 31 + 53) % 32);
        }
    }

    src_linesize = width;
    dst_linesize = width;

    size_t src_size = (size_t)height * src_linesize * sizeof(int16_t);
    size_t dst_size = (size_t)height * dst_linesize * sizeof(uint16_t);

    src = (int16_t*)aligned_alloc(32, src_size);
    dst = (uint16_t*)aligned_alloc(32, dst_size);

    if (!src || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < src_size / sizeof(int16_t); i++) {
        src[i] = (int16_t)(rand() % 1024 - 512);
    }
    memset(dst, 0, dst_size);
}

__attribute__((destructor))
static void cleanup() {
    free(src);
    free(dst);
}