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
for (i = 0; i < h; i++) {
    uint8_t *dst0 = dst;
    uint8_t *src0 = src;
    for (int j = 0; j < 4; j++) {
        ((((union unaligned_64 *)(dst0 + j * 2 * sizeof(uint16_t)))->l) = ((((const union unaligned_64 *)(src0 + j * 2 * sizeof(uint16_t)))->l)));
    }
    dst += dstStride;
    src += srcStride;
}
}
