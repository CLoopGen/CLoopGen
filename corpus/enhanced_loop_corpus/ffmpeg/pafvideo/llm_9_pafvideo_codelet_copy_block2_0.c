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
for (i = 0; i < h * 2; i++) {
    ((((union unaligned_16 *)(dst + (i % 2) * sizeof(uint16_t)))->l) = ((((const union unaligned_16 *)(src + (i % 2) * sizeof(uint16_t)))->l)));
    if (i % 2 == 1) {
        dst += dstStride;
        src += srcStride;
    }
}
}
