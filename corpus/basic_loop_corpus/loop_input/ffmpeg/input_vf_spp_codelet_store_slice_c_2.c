#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

uint8_t *dst;
int16_t *src;
int dst_linesize;
int src_linesize;
int width;
int height;
int log2_scale;
uint8_t dither[8][8];
int y;
int x;

void init_vars() {
    width = 1024;
    height = 128;
    log2_scale = 4;

    src_linesize = width;
    dst_linesize = width;

    src = (int16_t*)calloc(src_linesize * height, sizeof(int16_t));
    dst = (uint8_t*)malloc(dst_linesize * height * sizeof(uint8_t));

    for (int i = 0; i < src_linesize * height; i++) {
        src[i] = (int16_t)(i % 512);
    }

    for (int i = 0; i < dst_linesize * height; i++) {
        dst[i] = 0;
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            dither[i][j] = (uint8_t)((i * 17 + j * 31 + 1) % 64);
        }
    }

    y = 0;
    x = 0;
}