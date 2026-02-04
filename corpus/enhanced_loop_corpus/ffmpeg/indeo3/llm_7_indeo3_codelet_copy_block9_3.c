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
uint64_t prev_load = 0;
for (i = 0; i < h; i++) {
    uint64_t curr_load = ((const union unaligned_64 *)(src))->l;
    ((union unaligned_64 *)(dst))->l = prev_load + curr_load;
    dst[8] = src[8];
    prev_load = curr_load;
    dst += dstStride;
    src += srcStride;
}
}
