#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t dstStride;
extern ptrdiff_t srcStride;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    ptrdiff_t offset;
    // Use strided access with increasing offsets in multiples of 4
    for (int step = 0; step <= 8; step += 4) {
        offset = step;
        if (offset == 8) {
            dst[offset] = src[offset];
        } else {
            ((((union unaligned_64 *)(dst + offset))->l) = ((((const union unaligned_64 *)(src + offset))->l)));
        }
    }
    dst += dstStride;
    src += srcStride;
}
}
