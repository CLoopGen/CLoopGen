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
    uint32_t temp;
    if (h > 10 || i % 2 == 0) {
        temp = ((const union unaligned_32 *)(src))->l;
        ((union unaligned_32 *)(dst))->l = temp;
    }
    dst += dstStride;
    src += srcStride;
}
}
