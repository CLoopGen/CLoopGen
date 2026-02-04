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
int chromWidth;

static uint8_t *src_buffer;
static uint8_t *ydst_buffer;
static uint8_t *udst_buffer;
static uint8_t *vdst_buffer;

void init_vars() {
    chromWidth = 512;
    height = 512;
    lumStride = 1024;
    chromStride = 512;
    srcStride = 2048;

    size_t src_size = (size_t)srcStride * height;
    size_t ydst_size = (size_t)lumStride * height;
    size_t udst_size = (size_t)chromStride * height / 2;
    size_t vdst_size = (size_t)chromStride * height / 2;

    src_buffer = (uint8_t*)calloc(src_size, 1);
    ydst_buffer = (uint8_t*)calloc(ydst_size, 1);
    udst_buffer = (uint8_t*)calloc(udst_size, 1);
    vdst_buffer = (uint8_t*)calloc(vdst_size, 1);

    for (size_t i = 0; i < src_size; i++) {
        src_buffer[i] = (uint8_t)(i % 256);
    }

    src = src_buffer;
    ydst = ydst_buffer;
    udst = udst_buffer;
    vdst = vdst_buffer;
}