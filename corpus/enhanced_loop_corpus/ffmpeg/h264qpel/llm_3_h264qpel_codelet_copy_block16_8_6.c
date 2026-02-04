#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with vertical traversal pattern
    // Reorganize access to step through each column position across all rows first,
    // then move to next column index — changes spatial access pattern
    // Assumes h is number of rows and we are copying 4x4 byte blocks per row
    for (int col = 0; col < 4; col++) {
        uint8_t *base_dst = dst - col * 4 * sizeof(uint8_t); // Reset base
        const uint8_t *base_src = src - col * 4 * sizeof(uint8_t);
        for (i = 0; i < h; i++) {
            size_t offset = col * 4 * sizeof(uint8_t);
            ((union unaligned_32 *)(base_dst + offset))->l =
                ((const union unaligned_32 *)(base_src + offset))->l;
            base_dst += dstStride;
            base_src += srcStride;
        }
    }
    // Final update of dst and src to maintain interface expectations
    dst += h * dstStride;
    src += h * srcStride;
}
