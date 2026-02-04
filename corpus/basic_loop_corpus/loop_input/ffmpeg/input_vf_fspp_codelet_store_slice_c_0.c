#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

__attribute__((aligned(32))) uint8_t dither[8][8];
uint8_t *dst;
int16_t *src;
ptrdiff_t dst_stride;
ptrdiff_t src_stride;
ptrdiff_t width;
ptrdiff_t height;
ptrdiff_t log2_scale;
int y;
int x;

void init_vars() {
    // Set parameters to control data size and loop bounds
    width = 1024;
    height = 256;
    log2_scale = 2;  // typical value between 0-6, avoids shift overflow

    src_stride = width + 16;  // ensure alignment padding is safe
    dst_stride = width + 16;

    // Allocate large enough blocks to simulate ~tens to hundreds of ms runtime
    // Total operations: height * (width / 8) * 8 = height * width ≈ 262k pixels
    // This should be sufficient for measurable execution time

    // Allocate with padding to prevent out-of-bounds access
    // We access src[x + 7] and src[x - 8*src_stride], so we need:
    // - At least 8 rows before current in src for the first row
    // - So allocate extra rows at top and bottom
    int total_rows_src = height + 16;  // add 8 before and 8 after
    int total_elements_src = total_rows_src * src_stride;

    int total_rows_dst = height;
    int total_elements_dst = total_rows_dst * dst_stride;

    // Use calloc to avoid undefined values and initialize to zero
    int16_t *src_base = (int16_t*)calloc(total_elements_src, sizeof(int16_t));
    uint8_t *dst_base = (uint8_t*)calloc(total_elements_dst, sizeof(uint8_t));

    if (!src_base || !dst_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize dither pattern: simple Bayer matrix for demo
    static const uint8_t bayer8x8[8][8] = {
        {  0, 192,  48, 240,  12, 204,  60, 252 },
        {128,  64, 176, 112, 140,  76, 188, 124 },
        { 32, 224,  16, 208,  44, 236,  28, 220 },
        {160,  96, 144,  80, 172, 108, 156,  92 },
        {  8, 200,  56, 248,   4, 196,  52, 244 },
        {136,  72, 184, 120, 132,  68, 180, 116 },
        { 40, 232,  24, 216,  36, 228,  20, 212 },
        {168, 104, 152,  88, 164, 100, 148,  84 }
    };
    memcpy(dither, bayer8x8, sizeof(dither));

    // Set working pointers to middle of allocated region to allow negative indexing safely
    // We require up to 8 rows before current row: offset by 8 rows
    src = src_base + 8 * src_stride;
    dst = dst_base;

    // Initialize src with non-trivial but safe values
    for (int i = 0; i < total_elements_src; i++) {
        src_base[i] = (int16_t)(rand() % 512 - 256);  // small centered values
    }

    // Ensure that no temp overflows lead to UB during clamping
}