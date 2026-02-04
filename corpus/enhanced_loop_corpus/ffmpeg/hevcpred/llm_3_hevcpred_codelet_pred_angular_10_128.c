#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern int size;
extern int x;
extern  uint16_t *left;
extern uint16_t *ref_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive pairwise access using two consecutive elements per iteration
    for (x = 0; x <= size - 2; x += 4) {
        ((((union unaligned_64 *)(&ref_tmp[x]))->l) = ((((const union unaligned_64 *)(&left[x - 1]))->l)));
        ((((union unaligned_64 *)(&ref_tmp[x + 2]))->l) = ((((const union unaligned_64 *)(&left[x + 1]))->l)));
    }
}
