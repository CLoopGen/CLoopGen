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
    int offsets[4] = {0, 8, 16, 24};
    for (int j = 0; j < 4; j++) {
        int off = offsets[j];
        ((((union unaligned_64 *)(dst + off))->l) = ((((const union unaligned_64 *)(src + off))->l)));
    }
    dst += dstStride;
    src += srcStride;
}
}
