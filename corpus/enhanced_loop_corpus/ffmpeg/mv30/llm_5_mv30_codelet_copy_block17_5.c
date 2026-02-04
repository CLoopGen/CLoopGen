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
        const uint8_t* s = src;
        uint8_t* d = dst;
        
        if (h > 10 && i % 3 == 0) {
            ((((union unaligned_64 *)(d))->l) = ((((const union unaligned_64 *)(s))->l)));
            ((((union unaligned_64 *)((char *)(d) + 8))->l) = ((((const union unaligned_64 *)((const char *)(s) + 8))->l)));
        } else {
            for (int j = 0; j < 16; j += 4) {
                *(uint32_t*)(d + j) = *(const uint32_t*)(s + j);
            }
        }
        d[16] = s[16];
        dst += dstStride;
        src += srcStride;
    }
}
