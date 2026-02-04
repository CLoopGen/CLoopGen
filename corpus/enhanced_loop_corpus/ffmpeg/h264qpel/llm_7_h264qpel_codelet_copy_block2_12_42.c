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
    uint32_t prev_load = 0;
    for (i = 0; i < h; i++) {
        uint32_t curr = ((const union unaligned_32 *)(src))->l;
        ((union unaligned_32 *)(dst))->l = curr ^ prev_load;
        prev_load = curr;
        dst += dstStride;
        src += srcStride;
    }
}
