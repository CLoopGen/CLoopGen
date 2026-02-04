#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

uint8_t *src;
uint8_t *ydst;
uint8_t *udst;
uint8_t *vdst;
int height;
int lumStride;
int chromStride;
int srcStride;
int32_t ry;
int32_t gy;
int32_t by;
int32_t ru;
int32_t gu;
int32_t bu;
int32_t rv;
int32_t gv;
int32_t bv;
int y;
int chromWidth;

void init_vars() {
    // Set constants for RGB to YUV conversion (approximate standard BT.601 coefficients)
    ry = 19595;   // 0.257 * (1 << 15)
    gy = 38470;   // 0.504 * (1 << 15)
    by = 7471;    // 0.098 * (1 << 15)
    ru = -11059;  // -0.148 * (1 << 15)
    gu = -21709;  // -0.291 * (1 << 15)
    bu = 32768;   // 0.439 * (1 << 15)
    rv = 32768;   // 0.439 * (1 << 15)
    gv = -27439;  // -0.368 * (1 << 15)
    bv = 5329;    // 0.071 * (1 << 15)

    // Define image dimensions targeting ~64-128MB of input data
    // Each pixel uses 3 bytes in src (RGB), processed in pairs: 6 bytes per chroma pixel
    chromWidth = 1920;           // e.g., 1080p equivalent chroma width
    height = 1080;
    lumStride = 1920 * 2;        // Luma stride for 2x width (packed Y)
    chromStride = 1920;          // Chroma planes stride
    srcStride = 1920 * 3;        // RGB stride: 3 bytes per pixel

    // Allocate memory
    size_t srcSize = (size_t)srcStride * height;
    size_t ydstSize = (size_t)lumStride * height;
    size_t udstSize = (size_t)chromStride * ((height + 1) / 2);
    size_t vdstSize = (size_t)chromStride * ((height + 1) / 2);

    src = (uint8_t*)malloc(srcSize);
    ydst = (uint8_t*)malloc(ydstSize);
    udst = (uint8_t*)malloc(udstSize);
    vdst = (uint8_t*)malloc(vdstSize);

    // Initialize src with non-zero test pattern to avoid all-zero optimizations
    for (size_t i = 0; i < srcSize; i++) {
        src[i] = (uint8_t)(i % 256);
    }

    // Zero output buffers
    memset(ydst, 0, ydstSize);
    memset(udst, 0, udstSize);
    memset(vdst, 0, vdstSize);
}

// Ensure definitions are present even if not referenced elsewhere
static void __attribute__((constructor)) init() {
    init_vars();
}