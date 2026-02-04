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
    // Aim for approximately 16-32 MB of total data to target ~0.01s runtime
    const int width = 1920;
    height = 1080 * 4; // Multiple frames to increase workload

    lumStride = width;
    chromStride = width / 2;
    srcStride = width * 2; // Assuming YUYV or similar packed format

    size_t src_size = srcStride * height * 2; // *2 due to y +=2 and stepping by srcStride twice
    size_t ydst_size = lumStride * height * 2;
    size_t udst_size = chromStride * height;
    size_t vdst_size = chromStride * height;

    // Allocate buffers with padding to prevent overflow
    src_buffer = (uint8_t*)aligned_alloc(32, src_size);
    ydst_buffer = (uint8_t*)aligned_alloc(32, ydst_size);
    udst_buffer = (uint8_t*)aligned_alloc(32, udst_size);
    vdst_buffer = (uint8_t*)aligned_alloc(32, vdst_size);

    // Initialize pointers
    src = src_buffer;
    ydst = ydst_buffer;
    udst = udst_buffer;
    vdst = vdst_buffer;

    // Ensure initial values are set
    y = 0;
}