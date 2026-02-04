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
    uint32_t temp1, temp2;
    for (i = 0; i < h; i++) {
        temp1 = ((const union unaligned_32 *)(src))->l;
        temp2 = ((const union unaligned_32 *)(src + 4))->l;
        ((union unaligned_32 *)(dst))->l = temp1;
        ((union unaligned_32 *)(dst + 4))->l = temp2;
        dst += dstStride;
        src += srcStride;
    }
}
