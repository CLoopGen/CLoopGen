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
    size_t offset = i * srcStride;
    ((((union unaligned_64 *)(dst + 0))->l) = ((((const union unaligned_64 *)(src + offset))->l)));
    if (srcStride >= 8 + 4 * sizeof(uint16_t)) {
        ((((union unaligned_64 *)(dst + 4 * sizeof(uint16_t)))->l) = ((((const union unaligned_64 *)(src + offset + 4 * sizeof(uint16_t)))->l)));
    }
    dst += dstStride;
}
}
