#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width = 1024;
int height = 512;
int dst_linesize = 1024;
uint16_t *dst;
float *img_out_f;

void init_vars() {
    dst = (uint16_t*)aligned_alloc(32, (size_t)dst_linesize * height * sizeof(uint16_t));
    img_out_f = (float*)aligned_alloc(32, (size_t)width * height * sizeof(float));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            img_out_f[i * width + j] = (float)(i * width + j);
        }
    }
}