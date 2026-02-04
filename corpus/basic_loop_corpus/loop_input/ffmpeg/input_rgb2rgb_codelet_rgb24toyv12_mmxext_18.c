#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint8_t *ydst;
uint8_t *udst;
uint8_t *vdst;
int height;
int lumStride;
int chromStride;
int srcStride;
int y;

static uint8_t *src_buf;
static uint8_t *ydst_buf;
static uint8_t *udst_buf;
static uint8_t *vdst_buf;

void init_vars() {
    lumStride = 1920;
    chromStride = 960;
    srcStride = 1920;
    height = 1080;

    size_t src_size = (size_t)srcStride * height;
    size_t ydst_size = (size_t)lumStride * height;
    size_t udst_size = (size_t)chromStride * (height / 2);
    size_t vdst_size = (size_t)chromStride * (height / 2);

    src_buf = (uint8_t*)aligned_alloc(32, src_size);
    ydst_buf = (uint8_t*)aligned_alloc(32, ydst_size);
    udst_buf = (uint8_t*)aligned_alloc(32, udst_size);
    vdst_buf = (uint8_t*)aligned_alloc(32, vdst_size);

    if (!src_buf || !ydst_buf || !udst_buf || !vdst_buf) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    src = src_buf;
    ydst = ydst_buf;
    udst = udst_buf;
    vdst = vdst_buf;

    y = 0;
}