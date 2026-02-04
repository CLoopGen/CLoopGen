#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *ysrc;
uint8_t *usrc;
uint8_t *vsrc;
uint8_t *dst;
int height;
int lumStride;
int chromStride;
int dstStride;
int vertLumPerChroma;
int y;

static uint8_t *ysrc_data;
static uint8_t *usrc_data;
static uint8_t *vsrc_data;
static uint8_t *dst_data;

void init_vars() {
    lumStride = 1920;
    chromStride = 960;
    dstStride = 1920;
    height = 1080;
    vertLumPerChroma = 2;

    size_t y_size = (size_t)lumStride * height;
    size_t uv_size = (size_t)chromStride * ((height + vertLumPerChroma - 1) / vertLumPerChroma);

    ysrc_data = aligned_alloc(32, y_size);
    usrc_data = aligned_alloc(32, uv_size);
    vsrc_data = aligned_alloc(32, uv_size);
    dst_data = aligned_alloc(32, y_size);

    ysrc = ysrc_data;
    usrc = usrc_data;
    vsrc = vsrc_data;
    dst = dst_data;

    for (size_t i = 0; i < y_size; i++) {
        ysrc_data[i] = rand() & 0xFF;
        dst_data[i] = rand() & 0xFF;
    }
    for (size_t i = 0; i < uv_size; i++) {
        usrc_data[i] = rand() & 0xFF;
        vsrc_data[i] = rand() & 0xFF;
    }
}