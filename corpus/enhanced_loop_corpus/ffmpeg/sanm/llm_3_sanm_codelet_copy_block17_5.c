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
        // Variant 2: Strided memory access – process every 4th byte as part of a scattered pattern (simulated stride over 32-bit chunks)
        uint8_t *d = dst;
        const uint8_t *s = src;
        
        for (int j = 0; j < 17; j += 4) {
            *(uint32_t*)(d + j) = *(const uint32_t*)(s + j);
        }

        dst += dstStride;
        src += srcStride;
    }
}
