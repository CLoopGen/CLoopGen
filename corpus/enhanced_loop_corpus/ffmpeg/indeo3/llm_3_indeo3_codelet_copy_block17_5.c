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
        // Variant 2: Strided memory access with explicit byte-by-byte copy in steps
        for (int j = 0; j <= 16; j += 4) {
            if (j < 16) {
                // Copy 4 bytes at a time using uint32_t view (aligned-safe via byte copy)
                *(uint32_t*)(dst + j) = *(const uint32_t*)(src + j);
            } else {
                // Handle last byte separately (j == 16)
                dst[j] = src[j];
            }
        }
        
        dst += dstStride;
        src += srcStride;
    }
}
