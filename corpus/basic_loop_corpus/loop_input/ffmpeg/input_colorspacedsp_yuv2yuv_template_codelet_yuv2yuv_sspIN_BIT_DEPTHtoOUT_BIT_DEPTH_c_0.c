#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t src_stride[3];
int w;
int h;
uint16_t *src1;
uint16_t *src2;
int y;
int x;
int rnd;
int y_off_out;
int uv_off_in;
int cyu;
int cyv;

void init_vars() {
    w = 2048;
    h = 128;
    rnd = 1 << 13;
    y_off_out = 1 << 14;
    uv_off_in = 512;
    cyu = 240;
    cyv = 160;

    src_stride[1] = w * sizeof(uint16_t);
    src_stride[2] = w * sizeof(uint16_t);

    size_t total_size = (size_t)w * h * sizeof(uint16_t);

    src1 = aligned_alloc(32, total_size);
    src2 = aligned_alloc(32, total_size);

    if (!src1 || !src2) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < (size_t)w * h; i++) {
        src1[i] = rand() % 1024;
        src2[i] = rand() % 1024;
    }
}