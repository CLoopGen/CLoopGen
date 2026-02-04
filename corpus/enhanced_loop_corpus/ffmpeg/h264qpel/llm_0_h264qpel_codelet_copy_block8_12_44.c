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
    int i_outer;
    for (i_outer = 0; i_outer < h; i_outer++) {
        i = i_outer;
        ((((union unaligned_64 *)(dst + i * dstStride))->l) = ((((const union unaligned_64 *)(src + i * srcStride))->l)));
        ((((union unaligned_64 *)(dst + i * dstStride + 4 * sizeof(uint16_t)))->l) = ((((const union unaligned_64 *)(src + i * srcStride + 4 * sizeof(uint16_t)))->l)));
    }
}
