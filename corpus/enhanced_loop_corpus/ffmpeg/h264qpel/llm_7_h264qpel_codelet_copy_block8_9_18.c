#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
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
        uint64_t* d = (uint64_t*)dst;
        const uint64_t* s = (const uint64_t*)src;
        d[0] = s[0];
        d[1] = s[1];
        // Introduce artificial write-after-write dependency to force ordering
        // and create loop-carried dependency via dummy computation
        if (i > 0) {
            ((union unaligned_64 *)(dst - dstStride))->l ^= ((union unaligned_64 *)(dst))->l;
        }
        dst += dstStride;
        src += srcStride;
    }
}
