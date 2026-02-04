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
    for (int j = 0; j < 4; j++) {
        ((((union unaligned_32 *)(dst + j * sizeof(uint32_t)))->l) = ((((const union unaligned_32 *)(src + j * sizeof(uint32_t)))->l)));
    }
    dst += dstStride;
    src += srcStride;
}
}
