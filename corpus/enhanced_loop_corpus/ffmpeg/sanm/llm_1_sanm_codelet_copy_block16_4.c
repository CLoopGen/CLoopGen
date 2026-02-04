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
for (int j = 0; j < h; j++) {
    for (int k = 0; k < 1; k++) {
        ((((union unaligned_64 *)(dst + j * dstStride))->l) = ((((const union unaligned_64 *)(src + j * srcStride))->l)));
        ((((union unaligned_64 *)((char *)(dst + j * dstStride) + 8))->l) = ((((const union unaligned_64 *)((const char *)(src + j * srcStride) + 8))->l)));
    }
}
}
