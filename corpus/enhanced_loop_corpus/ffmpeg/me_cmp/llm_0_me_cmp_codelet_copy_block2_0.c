#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};


extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t dstStride;
extern ptrdiff_t srcStride;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int outer = 0; outer < h; outer += 2) {
    for (int inner = 0; inner < 2 && (outer + inner) < h; inner++) {
        int current_i = outer + inner;
        ((((union unaligned_16 *)(dst + current_i * dstStride))->l) = ((((const union unaligned_16 *)(src + current_i * srcStride))->l)));
    }
}
}
