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



void loop(){
    for (i = 0; i < h; i++) {
        // Variant 1: Consecutive memory access with full 24-byte copy using direct pointer arithmetic
        uint64_t *dst64 = (uint64_t*)dst;
        const uint64_t *src64 = (const uint64_t*)src;
        
        dst64[0] = src64[0];
        dst64[1] = src64[1];
        dst[16] = src[16];
        
        dst += dstStride;
        src += srcStride;
    }
}
