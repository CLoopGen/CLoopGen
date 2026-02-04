#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *ysrc;
uint8_t *usrc;
uint8_t *vsrc;
uint8_t *dst;

int height = 1080;
int lumStride = 1920;
int chromStride = 960;
int dstStride = 3840;
int vertLumPerChroma = 2;
int y;
int i;
int chromWidth = 960;

static uint8_t *ysrc_data;
static uint8_t *usrc_data;
static uint8_t *vsrc_data;
static uint8_t *dst_data;

void init_vars() {
    const int lumHeight = 1080;
    const int lumWidth = 1920;
    const int chromWidth_pixels = 960;
    const int chromHeight = 540;

    ysrc_data = aligned_alloc(32, (size_t)lumHeight * lumStride);
    usrc_data = aligned_alloc(32, (size_t)chromHeight * chromStride);
    vsrc_data = aligned_alloc(32, (size_t)chromHeight * chromStride);
    dst_data = aligned_alloc(32, (size_t)lumHeight * dstStride);

    ysrc = ysrc_data;
    usrc = usrc_data;
    vsrc = vsrc_data;
    dst = dst_data;

    for (int i = 0; i < lumHeight * lumStride; i++) {
        ysrc_data[i] = rand() % 256;
    }
    for (int i = 0; i < chromHeight * chromStride; i++) {
        usrc_data[i] = rand() % 256;
        vsrc_data[i] = rand() % 256;
    }
    for (int i = 0; i < lumHeight * dstStride; i++) {
        dst_data[i] = 0;
    }

    height = lumHeight;
    lumStride = lumStride;
    chromStride = chromStride;
    dstStride = dstStride;
    vertLumPerChroma = 2;
    chromWidth = chromWidth_pixels;
}