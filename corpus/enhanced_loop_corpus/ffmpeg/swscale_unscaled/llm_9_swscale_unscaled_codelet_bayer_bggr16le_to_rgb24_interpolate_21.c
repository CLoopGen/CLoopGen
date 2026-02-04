#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};


extern  uint8_t *src;
extern int src_stride;
extern uint8_t *dst;
extern int dst_stride;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced computation: downsampled processing with simplified operations
for (i = 4; i < width - 4; i += 4) {
    // Skip every other macroblock and reduce arithmetic density

    // Load only central and key neighbor values
    uint16_t center     = ((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (0)])))->l;
    uint16_t right      = ((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (2)])))->l;
    uint16_t below      = ((const union unaligned_16 *)(&(src[(2) * src_stride + 2 * (0)])))->l;
    uint16_t below_right= ((const union unaligned_16 *)(&(src[(2) * src_stride + 2 * (2)])))->l;

    // Simplified averaging: only corner-averaged output and center pass-through
    dst[(0) * dst_stride + (0) * 3 + 0] = (center + right + below + below_right) >> 10;  // Avg of corners >> 10
    dst[(0) * dst_stride + (0) * 3 + 1] = center >> 8;  // Just MSB of center
    dst[(0) * dst_stride + (0) * 3 + 2] = 0;            // Unused channel set to zero

    // Skip intermediate values, only write one 2x2 reduced block
    dst[(0) * dst_stride + (1) * 3 + 0] = (right + below_right) >> 9;
    dst[(0) * dst_stride + (1) * 3 + 1] = right >> 8;
    dst[(0) * dst_stride + (1) * 3 + 2] = 0;

    dst[(1) * dst_stride + (0) * 3 + 0] = (below + below_right) >> 9;
    dst[(1) * dst_stride + (0) * 3 + 1] = below >> 8;
    dst[(1) * dst_stride + (0) * 3 + 2] = 0;

    dst[(1) * dst_stride + (1) * 3 + 0] = below_right >> 8;
    dst[(1) * dst_stride + (1) * 3 + 1] = 0;
    dst[(1) * dst_stride + (1) * 3 + 2] = 0;

    // Stride forward by 4 pixels (8 bytes) in source, 6 bytes in destination
    src += 4 * 2;
    dst += 6;
}
}
