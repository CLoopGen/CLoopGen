#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t yuv_stride[3];
int w;
int h;
uint16_t *yuv1;
uint16_t *yuv2;
int y;
int x;
int uv_offset;

static uint16_t *buffer_yuv1;
static uint16_t *buffer_yuv2;

void init_vars() {
    w = 1920;
    h = 1080;
    uv_offset = 512;

    yuv_stride[1] = w * sizeof(uint16_t);
    yuv_stride[2] = w * sizeof(uint16_t);

    size_t yuv_size = (size_t)w * h;

    buffer_yuv1 = aligned_alloc(32, yuv_size * sizeof(uint16_t));
    buffer_yuv2 = aligned_alloc(32, yuv_size * sizeof(uint16_t));

    if (!buffer_yuv1 || !buffer_yuv2) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < yuv_size; i++) {
        buffer_yuv1[i] = rand() % 1024;
        buffer_yuv2[i] = rand() % 1024;
    }

    yuv1 = buffer_yuv1;
    yuv2 = buffer_yuv2;
}