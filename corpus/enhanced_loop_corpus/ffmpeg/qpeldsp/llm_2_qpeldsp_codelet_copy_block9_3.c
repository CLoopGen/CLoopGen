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
    uint8_t *d = dst + 4;
    const uint8_t *s = src + 4;
    ((((union unaligned_64 *)(d - 4))->l) = ((((const union unaligned_64 *)(s - 4))->l)));
    ;
    d[4] = s[4];
    dst += dstStride;
    src += srcStride;
}
}
