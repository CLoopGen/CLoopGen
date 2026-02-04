#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE_MB 64

uint8_t *dst;
int stride;
int b_w;
int b_h;
int x;
int y;
uint8_t *src1;
uint8_t *src2;
int stride1;
int stride2;
int a;
int b;

static uint8_t *alloc_aligned(size_t size) {
    void *ptr;
    if (posix_memalign(&ptr, 32, size) != 0) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    return (uint8_t *)ptr;
}

void init_vars() {
    const int width = 2048;
    const int height = (DATA_SIZE_MB * 1024 * 1024) / (3 * width); 
    b_w = width;
    b_h = height < 1 ? 1 : (height > 32768 ? 32768 : height);

    stride1 = width;
    stride2 = width;
    stride = width;

    a = 3;
    b = 5;

    src1 = alloc_aligned((size_t)stride1 * b_h);
    src2 = alloc_aligned((size_t)stride2 * b_h);
    dst = alloc_aligned((size_t)stride * b_h);

    for (int i = 0; i < b_h; i++) {
        for (int j = 0; j < b_w; j++) {
            src1[i * stride1 + j] = rand() % 256;
            src2[i * stride2 + j] = rand() % 256;
        }
    }
}