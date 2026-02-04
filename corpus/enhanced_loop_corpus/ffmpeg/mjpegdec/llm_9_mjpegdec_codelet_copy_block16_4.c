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
int step = 2;
for (i = 0; i < h - 1; i += step) {
    ((((union unaligned_64 *)(dst))->l) = ((((const union unaligned_64 *)(src))->l)));
    ((((union unaligned_64 *)((char *)(dst) + 8))->l) = ((((const union unaligned_64 *)((const char *)(src) + 8))->l)));
    dst += dstStride;
    src += srcStride;

    ((((union unaligned_64 *)(dst))->l) = ((((const union unaligned_64 *)(src))->l)));
    ((((union unaligned_64 *)((char *)(dst) + 8))->l) = ((((const union unaligned_64 *)((const char *)(src) + 8))->l)));
    dst += dstStride;
    src += srcStride;
}
// Handle remaining iteration if h is odd
if (i < h) {
    ((((union unaligned_64 *)(dst))->l) = ((((const union unaligned_64 *)(src))->l)));
    ((((union unaligned_64 *)((char *)(dst) + 8))->l) = ((((const union unaligned_64 *)((const char *)(src) + 8))->l)));
}
}
