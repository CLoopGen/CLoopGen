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
    // Define image dimensions to achieve ~100ms runtime
    // Assume processing 2 lines per iteration, adjust size accordingly
    lumStride = 1920;
    chromStride = 960;
    height = 1080;

    // Allocate buffers with padding to prevent overflow
    int src_size = srcStride * height * 2;
    int ydst_size = lumStride * height * 2;
    int udst_size = chromStride * height;
    int vdst_size = chromStride * height;

    srcStride = lumStride * 2; // assuming subsampled chroma in source

    src_buffer = calloc(src_size, sizeof(uint8_t));
    ydst_buffer = calloc(ydst_size, sizeof(uint8_t));
    udst_buffer = calloc(udst_size, sizeof(uint8_t));
    vdst_buffer = calloc(vdst_size, sizeof(uint8_t));

    if (!src_buffer || !ydst_buffer || !udst_buffer || !vdst_buffer) {
        exit(1);
    }

    src = src_buffer;
    ydst = ydst_buffer;
    udst = udst_buffer;
    vdst = vdst_buffer;
}