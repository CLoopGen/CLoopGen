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
    uint64_t temp1 = (((const union unaligned_64 *)(src))->l);
    uint64_t temp2 = (((const union unaligned_64 *)(src + 8))->l);
    ((((union unaligned_64 *)(dst))->l) = temp1);
    ((((union unaligned_64 *)(dst + 8))->l) = temp2);
    ((((union unaligned_64 *)(dst + 16))->l) = temp1 ^ temp2);
    dst += dstStride;
    src += srcStride;
}
}
