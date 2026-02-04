#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
ptrdiff_t linesize;
int w;
int h;
float *histogram;
int y;
int x;

void init_vars() {
    w = 8192;
    h = 8192;
    linesize = w + 64;

    uint8_t *src_data = (uint8_t*)aligned_alloc(64, (size_t)h * (size_t)linesize);
    float *hist_data = (float*)aligned_alloc(64, 256 * sizeof(float));

    if (!src_data || !hist_data) {
        exit(1);
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            src_data[i * linesize + j] = rand() % 256;
        }
    }

    for (int i = 0; i < 256; i++) {
        hist_data[i] = 0.0f;
    }

    src = src_data;
    histogram = hist_data;
}