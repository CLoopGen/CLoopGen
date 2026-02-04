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
        ((((union unaligned_64 *)(dst))->l) = ((((const union unaligned_64 *)(src))->l)));
        ((((union unaligned_64 *)((char *)(dst) + 8))->l) = ((((const union unaligned_64 *)((const char *)(src) + 8))->l)));
        dst[16] = src[16];

        // Add computational overhead: simulate a small processing load
        volatile uint64_t acc = 0;
        for (int j = 0; j < 16; j++) {
            acc += ((uint64_t)(dst[j]) * (src[j])) ^ 0x55AA55AA;
        }
        // Prevent optimization of the above loop
        if (acc == 0) {
            dst[0] ^= 1;
        }

        dst += dstStride;
        src += srcStride;
    }
}
