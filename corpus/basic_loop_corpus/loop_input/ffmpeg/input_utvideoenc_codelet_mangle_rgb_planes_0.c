#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

uint8_t *dst[4];
ptrdiff_t dst_stride;
int planes = 3;
int stride[4];
int width;
int height;
int i, j, k;
uint8_t *sg;
uint8_t *sb;
uint8_t *sr;
uint8_t *sa;
unsigned int g;

static uint8_t *alloc_aligned(size_t size) {
    void *ptr;
    if (posix_memalign(&ptr, 32, size) != 0) {
        exit(1);
    }
    return (uint8_t*)ptr;
}

void init_vars() {
    width = 1920;
    height = 1080;
    dst_stride = 2048;
    planes = 3;

    stride[0] = width;
    stride[1] = width;
    stride[2] = width;
    stride[3] = width;

    size_t src_size = width * height;
    size_t dst_plane_size = dst_stride * height;

    sg = alloc_aligned(src_size);
    sb = alloc_aligned(src_size);
    sr = alloc_aligned(src_size);
    sa = alloc_aligned(src_size);

    for (int p = 0; p < 4; p++) {
        dst[p] = alloc_aligned(dst_plane_size);
    }

    k = 0;

    for (size_t idx = 0; idx < src_size; idx++) {
        sg[idx] = rand() % 256;
        sb[idx] = rand() % 256;
        sr[idx] = rand() % 256;
        sa[idx] = rand() % 256;
    }

    for (int p = 0; p < 4; p++) {
        memset(dst[p], 0, dst_plane_size);
    }
}