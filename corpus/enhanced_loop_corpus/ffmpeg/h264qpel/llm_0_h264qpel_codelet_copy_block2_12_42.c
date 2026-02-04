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
    for (int outer = 0; outer < h; outer += 2) {
        int i = outer;
        ((((union unaligned_32 *)(dst))->l) = ((((const union unaligned_32 *)(src))->l)));
        dst += dstStride;
        src += srcStride;
        if (outer + 1 < h) {
            i = outer + 1;
            ((((union unaligned_32 *)(dst))->l) = ((((const union unaligned_32 *)(src))->l)));
            dst += dstStride;
            src += srcStride;
        }
    }
}
