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
    int offset = 0;
    if (i % 2 == 0) {
        ((((union unaligned_32 *)(dst + offset))->l) = ((((const union unaligned_32 *)(src + offset))->l)));
        offset += 4;
        ((((union unaligned_32 *)(dst + offset))->l) = ((((const union unaligned_32 *)(src + offset))->l)));
        offset += 4;
        ((((union unaligned_32 *)(dst + offset))->l) = ((((const union unaligned_32 *)(src + offset))->l)));
        offset += 4;
        ((((union unaligned_32 *)(dst + offset))->l) = ((((const union unaligned_32 *)(src + offset))->l)));
    } else {
        while (offset < 16) {
            ((((union unaligned_32 *)(dst + offset))->l) = ((((const union unaligned_32 *)(src + offset))->l)));
            offset += 4;
        }
    }
    dst += dstStride;
    src += srcStride;
}
}
