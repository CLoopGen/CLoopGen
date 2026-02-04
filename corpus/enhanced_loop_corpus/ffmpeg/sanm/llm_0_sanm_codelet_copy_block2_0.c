#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};


extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t dstStride;
extern ptrdiff_t srcStride;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int outer = 0; outer < h; outer++) {
    for (int inner = 0; inner < 1; inner++) {
        ((((union unaligned_16 *)(dst))->l) = ((((const union unaligned_16 *)(src))->l)));
        ;
        dst += dstStride;
        src += srcStride;
    }
}
}
