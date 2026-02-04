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
    int temp_h = h;
    h = 1;
    for (i = 0; i < temp_h; i++) {
        for (int j = 0; j < 1; j++) {
            ((((union unaligned_64 *)(dst + j * dstStride))->l) = ((((const union unaligned_64 *)(src + j * srcStride))->l)));
            ((((union unaligned_64 *)(dst + j * dstStride + 4 * sizeof(uint16_t)))->l) = ((((const union unaligned_64 *)(src + j * srcStride + 4 * sizeof(uint16_t)))->l)));
        }
        dst += dstStride;
        src += srcStride;
    }
    h = temp_h;
}
