#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

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
int i;
int chromWidth;

static uint8_t *ysrc_data;
static uint8_t *usrc_data;
static uint8_t *vsrc_data;
static uint8_t *dst_data;

void init_vars() {
    // Set parameters to achieve ~10-100ms runtime on modern CPU
    // Aim for total data size around 64-128 MB
    int lumWidth = 1920;
    height = 1080;
    vertLumPerChroma = 2;
    chromWidth = lumWidth / 2;
    
    lumStride = lumWidth;
    chromStride = chromWidth;
    dstStride = lumWidth * 4;  // RGBA or similar 32-bit format

    // Allocate memory with padding to prevent overflow
    ysrc_data = (uint8_t*)aligned_alloc(32, (size_t)lumStride * (size_t)height);
    usrc_data = (uint8_t*)aligned_alloc(32, (size_t)chromStride * ((size_t)height / vertLumPerChroma));
    vsrc_data = (uint8_t*)aligned_alloc(32, (size_t)chromStride * ((size_t)height / vertLumPerChroma));
    dst_data = (uint8_t*)aligned_alloc(32, (size_t)dstStride * (size_t)height);

    // Initialize pointers
    ysrc = ysrc_data;
    usrc = usrc_data;
    vsrc = vsrc_data;
    dst = dst_data;

    // Initialize input data with non-zero patterns
    for (int i = 0; i < lumStride * height; i++) {
        ysrc_data[i] = (uint8_t)(i & 0xFF);
    }
    for (int i = 0; i < chromStride * (height / vertLumPerChroma); i++) {
        usrc_data[i] = (uint8_t)((i + 33) & 0xFF);
        vsrc_data[i] = (uint8_t)((i + 65) & 0xFF);
    }
    for (int i = 0; i < dstStride * height; i++) {
        dst_data[i] = 0;
    }

    // Ensure all variables used in loop bounds are initialized
    y = 0;
    i = 0;
}