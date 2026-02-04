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
        // Variant 1: Consecutive memory access with unrolled copy using pointer arithmetic
        uint64_t *d = (uint64_t*)dst;
        const uint64_t *s = (const uint64_t*)src;
        
        d[0] = s[0];  // Copy first 8 bytes
        d[1] = s[1];  // Copy next 8 bytes
        dst[16] = src[16];  // Copy remaining byte
        
        dst += dstStride;
        src += srcStride;
    }
}
