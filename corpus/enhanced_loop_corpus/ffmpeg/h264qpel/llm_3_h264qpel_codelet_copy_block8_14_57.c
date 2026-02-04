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
    int offset = 0;
    while (offset < dstStride) {
        ((((union unaligned_64 *)(dst + offset))->l) = ((((const union unaligned_64 *)(src + offset))->l)));
        offset += sizeof(uint64_t);
    }
    dst += dstStride;
    src += srcStride;
}
}
