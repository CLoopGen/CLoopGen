#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *ysrc;
extern  uint8_t *usrc;
extern  uint8_t *vsrc;
extern uint8_t *dst;
extern int height;
extern int lumStride;
extern int chromStride;
extern int dstStride;
extern int vertLumPerChroma;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access via index-based array indexing with scaled offsets
    // Replace pointer arithmetic with explicit index calculations to create a strided access pattern.
    // This version uses byte offsets from base addresses, enabling better analysis in vectorizing compilers.

    for (y = 0; y < height; y++) {
        // Calculate current row offset in bytes using index-based arithmetic
        ptrdiff_t y_offset = (ptrdiff_t)y * lumStride;
        ptrdiff_t dst_offset = (ptrdiff_t)y * dstStride;

        // For chroma, update only at subsampled intervals using integer division
        ptrdiff_t chroma_row = (y + 1) / vertLumPerChroma;
        ptrdiff_t prev_chroma_row = y / vertLumPerChroma;

        if (chroma_row > prev_chroma_row) {
            ptrdiff_t chroma_offset = chroma_row * chromStride;
            usrc = usrc - (prev_chroma_row * chromStride) + chroma_offset; // Simulate forward jump
            vsrc = vsrc - (prev_chroma_row * chromStride) + chroma_offset;
        }

        // Touch data via calculated base + offset (strided access pattern)
        volatile uint8_t lum = ysrc[y_offset];
        volatile uint8_t out = dst[dst_offset];

        // Prevent unused warning; simulate use
        (void)lum;
        (void)out;
    }

    // Finalize pointer positions as in original semantics
    ysrc += height * lumStride;
    dst += height * dstStride;
}
