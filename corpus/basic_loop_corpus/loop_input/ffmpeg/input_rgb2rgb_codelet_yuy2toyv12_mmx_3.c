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

static uint8_t *src_buffer;
static uint8_t *ydst_buffer;
static uint8_t *udst_buffer;
static uint8_t *vdst_buffer;

void init_vars() {
    height = 1024;
    lumStride = 2048;
    chromStride = 1024;
    srcStride = 2048;

    size_t src_size = (size_t)(height + 1) * srcStride * 2;
    size_t ydst_size = (size_t)(height + 1) * lumStride * 2;
    size_t udst_size = (size_t)(height / 2 + 1) * chromStride * 2;
    size_t vdst_size = (size_t)(height / 2 + 1) * chromStride * 2;

    src_buffer = (uint8_t*)aligned_alloc(32, src_size);
    ydst_buffer = (uint8_t*)aligned_alloc(32, ydst_size);
    udst_buffer = (uint8_t*)aligned_alloc(32, udst_size);
    vdst_buffer = (uint8_t*)aligned_alloc(32, vdst_size);

    src = src_buffer;
    ydst = ydst_buffer;
    udst = udst_buffer;
    vdst = vdst_buffer;

    for (size_t i = 0; i < src_size; i++) {
        src_buffer[i] = rand() & 0xFF;
    }
    for (size_t i = 0; i < ydst_size; i++) {
        ydst_buffer[i] = rand() & 0xFF;
    }
    for (size_t i = 0; i < udst_size; i++) {
        udst_buffer[i] = rand() & 0xFF;
    }
    for (size_t i = 0; i < vdst_size; i++) {
        vdst_buffer[i] = rand() & 0xFF;
    }
}