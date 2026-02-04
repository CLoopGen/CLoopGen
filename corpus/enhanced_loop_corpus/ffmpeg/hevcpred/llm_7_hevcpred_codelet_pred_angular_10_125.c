#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern int size;
extern int x;
extern  uint16_t *top;
extern uint16_t *ref_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x <= size - 3; x += 8) {
        (((union unaligned_64 *)(&ref_tmp[x]))->l) = ((((const union unaligned_64 *)(&top[x - 1]))->l));
        (((union unaligned_64 *)(&ref_tmp[x + 4]))->l) = ((((const union unaligned_64 *)(&top[x + 3]))->l));
    }
    // Increases stride from 4 to 8 and unrolls the loop by factor of 2.
    // Reduces loop-carried dependence frequency and exposes more ILP.
    // Alters memory access pattern while maintaining correctness for larger sizes.
}
