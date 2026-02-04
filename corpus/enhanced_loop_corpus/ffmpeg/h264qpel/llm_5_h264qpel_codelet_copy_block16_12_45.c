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
    dst += dstStride;
    src += srcStride;
    if (i == h - 1) continue;
    ((((union unaligned_64 *)(dst))->l) = ((((const union unaligned_64 *)(src))->l)));
    ((((union unaligned_64 *)(dst + 4 * sizeof(uint16_t)))->l) = ((((const union unaligned_64 *)(src + 4 * sizeof(uint16_t)))->l)));
    if (i < h / 2) {
        ((((union unaligned_64 *)(dst + 8 * sizeof(uint16_t)))->l) = ((((const union unaligned_64 *)(src + 8 * sizeof(uint16_t)))->l)));
        ((((union unaligned_64 *)(dst + 12 * sizeof(uint16_t)))->l) = ((((const union unaligned_64 *)(src + 12 * sizeof(uint16_t)))->l)));
    }
}
}
