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
    for (i = 0; i < h; i++) {
        uint32_t *d = (uint32_t*)dst;
        const uint32_t *s = (const uint32_t*)src;

        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
        d[3] = s[3];

        // Introduce artificial write-after-write dependency to enforce ordering
        // This creates a WAW-like intra-loop dependency (though not carried)
        __asm__ volatile("" : "+m"(*d) : : "memory");

        dst += dstStride;
        src += srcStride;
    }
}
