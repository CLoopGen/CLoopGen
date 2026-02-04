#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern uint8_t *dst;
extern  uint8_t *src;
extern int width;
extern int height;
extern ptrdiff_t stride_dst;
extern ptrdiff_t stride_src;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp;
    for (i = 0; i < height; i++) {
        temp = 0;
        for (j = 0; j < width - 7; j += 8) {
            temp ^= ((((const union unaligned_64 *)(src + j))->l));
            ((((union unaligned_64 *)(dst + j))->l) = temp);
        }
        dst += stride_dst;
        src += stride_src;
    }
}
