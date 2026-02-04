#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
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
    if (dstStride >= 2 && srcStride >= 2) {
        ((((union unaligned_16 *)(dst))->l) = ((((const union unaligned_16 *)(src))->l)));
    } else {
        dst[0] = src[0];
        if (dstStride > 1 && srcStride > 1) {
            dst[1] = src[1];
        }
    }
    dst += dstStride;
    src += srcStride;
}
}
