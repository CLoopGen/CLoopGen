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
    if (h > 0) {
        i = 0;
        for (;;) {
            ((((union unaligned_64 *)(dst))->l) = ((((const union unaligned_64 *)(src))->l)));
            dst += dstStride;
            src += srcStride;
            i++;
            if (i >= h) break;
        }
    }
}
