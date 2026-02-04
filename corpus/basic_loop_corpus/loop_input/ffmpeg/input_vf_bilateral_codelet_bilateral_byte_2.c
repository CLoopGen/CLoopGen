#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width;
int height;
int dst_linesize;
uint8_t *dst;
float *img_out_f;

void init_vars() {
    width = 1024;
    height = 512;
    dst_linesize = width + 64;

    dst = (uint8_t*)aligned_alloc(32, (size_t)dst_linesize * height);
    img_out_f = (float*)aligned_alloc(32, (size_t)width * height * sizeof(float));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            img_out_f[i * width + j] = (float)((i * width + j) % 256);
        }
    }
}