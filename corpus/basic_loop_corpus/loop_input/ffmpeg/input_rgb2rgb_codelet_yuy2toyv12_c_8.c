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

static uint8_t *src_buf;
static uint8_t *ydst_buf;
static uint8_t *udst_buf;
static uint8_t *vdst_buf;

void init_vars() {
    // Set dimensions to achieve ~100ms runtime
    // Empirically, total data size around 64-128MB gives good timing
    chromWidth = 2048;
    height = 2048;
    lumStride = 4096;
    chromStride = 2048;
    srcStride = 8192;

    // Allocate buffers with padding to prevent overflow
    size_t src_size = (height + 1) * srcStride; // +1 for safety in loop
    size_t ydst_size = (height + 1) * lumStride;
    size_t udst_size = (height/2 + 1) * chromStride;
    size_t vdst_size = (height/2 + 1) * chromStride;

    src_buf = aligned_alloc(32, src_size);
    ydst_buf = aligned_alloc(32, ydst_size);
    udst_buf = aligned_alloc(32, udst_size);
    vdst_buf = aligned_alloc(32, vdst_size);

    // Initialize pointers
    src = src_buf;
    ydst = ydst_buf;
    udst = udst_buf;
    vdst = vdst_buf;

    // Initialize buffer contents to avoid undefined behavior
    for (size_t i = 0; i < src_size; i++) {
        src_buf[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < ydst_size; i++) {
        ydst_buf[i] = 0;
    }
    for (size_t i = 0; i < udst_size; i++) {
        udst_buf[i] = 0;
    }
    for (size_t i = 0; i < vdst_size; i++) {
        vdst_buf[i] = 0;
    }

    // Ensure chromWidth is even and fits within allocated widths
    chromWidth = (chromWidth > lumStride/2) ? lumStride/2 : chromWidth;
    chromWidth = (chromWidth > srcStride/4) ? srcStride/4 : chromWidth;
    chromWidth &= ~1; // Ensure even for safe processing

    // Adjust height to be multiple of 2
    height &= ~1;
}