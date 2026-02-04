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
for (i = 0; i < h * 2; i += 2) {
    int idx1 = i;
    int idx2 = i + 1;
    if (idx1 < h) {
        (((union unaligned_64 *)(dst + idx1 * dstStride))->l) = (((const union unaligned_64 *)(src + idx1 * srcStride))->l);
        (((union unaligned_64 *)((char *)(dst + idx1 * dstStride) + 8))->l) = (((const union unaligned_64 *)((const char *)(src + idx1 * srcStride) + 8))->l);
    }
    if (idx2 < h) {
        (((union unaligned_64 *)(dst + idx2 * dstStride))->l) = (((const union unaligned_64 *)(src + idx2 * srcStride))->l);
        (((union unaligned_64 *)((char *)(dst + idx2 * dstStride) + 8))->l) = (((const union unaligned_64 *)((const char *)(src + idx2 * srcStride) + 8))->l);
    }
}
}
