#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t dstStride;
extern ptrdiff_t srcStride;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 0; i < h; i++) {
        // Variant 1: Consecutive memory access with full 24-byte copy using pointer arithmetic and union access
        ((union unaligned_64 *)(dst + 0))->l = ((const union unaligned_64 *)(src + 0))->l;
        ((union unaligned_64 *)(dst + 8))->l = ((const union unaligned_64 *)(src + 8))->l;
        ((union unaligned_64 *)(dst + 16))->l = ((const union unaligned_64 *)(src + 16))->l;

        dst += dstStride;
        src += srcStride;
    }
}
