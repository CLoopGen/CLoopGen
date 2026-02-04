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
    int total_iterations = h * 1;
    for (int flat_i = 0; flat_i < total_iterations; flat_i++) {
        int i = flat_i; // Recover original i for stride logic
        ((((union unaligned_64 *)(dst))->l) = ((((const union unaligned_64 *)(src))->l)));
        ;
        dst += dstStride;
        src += srcStride;
    }
}
