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
    uint8_t *d = dst;
    const uint8_t *s = src;
    for (int j = 0; j < dstStride && j < srcStride; j += sizeof(uint64_t)) {
        ((((union unaligned_64 *)(d + j))->l) = ((((const union unaligned_64 *)(s + j))->l)));
    }
    dst += dstStride;
    src += srcStride;
}
}
