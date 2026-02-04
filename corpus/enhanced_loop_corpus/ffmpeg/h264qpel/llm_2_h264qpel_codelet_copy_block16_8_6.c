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
    // Variant 1: Consecutive memory access with unrolled sequential writes
    // Instead of strided access within a row, process 16 consecutive bytes as a block
    for (i = 0; i < h; i++) {
        uint8_t *d = dst;
        const uint8_t *s = src;
        // Copy 16 bytes consecutively using 4x 32-bit aligned-safe loads/stores
        ((union unaligned_32 *)(d + 0))->l = ((const union unaligned_32 *)(s + 0))->l;
        ((union unaligned_32 *)(d + 4))->l = ((const union unaligned_32 *)(s + 4))->l;
        ((union unaligned_32 *)(d + 8))->l = ((const union unaligned_32 *)(s + 8))->l;
        ((union unaligned_32 *)(d + 12))->l = ((const union unaligned_32 *)(s + 12))->l;
        dst += dstStride;
        src += srcStride;
    }
}
