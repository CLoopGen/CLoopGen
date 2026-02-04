#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
int stride;
int b_w;
int b_h;
int dx;
int dy;
int x;
int y;
uint8_t *src1;
uint8_t *src2;
uint8_t *src3;
uint8_t *src4;
int stride1;
int stride2;
int stride3;
int stride4;

static uint8_t *alloc_2d(int height, int width, int *stride_ptr) {
    uint8_t *data = (uint8_t*)aligned_alloc(64, height * width * sizeof(uint8_t));
    *stride_ptr = width;
    return data;
}

void init_vars() {
    b_w = 512;
    b_h = 512;
    dx = 4;
    dy = 4;

    stride1 = b_w;
    stride2 = b_w;
    stride3 = b_w;
    stride4 = b_w;
    stride = b_w;

    src1 = alloc_2d(b_h, b_w, &stride1);
    src2 = alloc_2d(b_h, b_w, &stride2);
    src3 = alloc_2d(b_h, b_w, &stride3);
    src4 = alloc_2d(b_h, b_w, &stride4);
    dst = alloc_2d(b_h, b_w, &stride);

    for (int i = 0; i < b_h; i++) {
        for (int j = 0; j < b_w; j++) {
            src1[i * stride1 + j] = rand() % 256;
            src2[i * stride2 + j] = rand() % 256;
            src3[i * stride3 + j] = rand() % 256;
            src4[i * stride4 + j] = rand() % 256;
        }
    }

    x = 0;
    y = 0;
}