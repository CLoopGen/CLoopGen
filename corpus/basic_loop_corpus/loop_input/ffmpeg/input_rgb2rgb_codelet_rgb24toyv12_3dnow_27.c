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

    src_buf = aligned_alloc(32, src_size);
    ydst_buf = aligned_alloc(32, ydst_size);
    udst_buf = aligned_alloc(32, udst_size);
    vdst_buf = aligned_alloc(32, vdst_size);

    src = src_buf;
    ydst = ydst_buf;
    udst = udst_buf;
    vdst = vdst_buf;

    for (size_t i = 0; i < src_size; i++) {
        src_buf[i] = i & 0xFF;
    }
    for (size_t i = 0; i < ydst_size; i++) {
        ydst_buf[i] = 0;
    }
    for (size_t i = 0; i < udst_size; i++) {
        udst_buf[i] = 128;
    }
    for (size_t i = 0; i < vdst_size; i++) {
        vdst_buf[i] = 128;
    }
}