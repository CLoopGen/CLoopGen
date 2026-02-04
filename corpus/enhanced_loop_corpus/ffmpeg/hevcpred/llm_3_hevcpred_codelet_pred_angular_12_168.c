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
    // Variant 2: Consecutive (unit-stride) access with unrolled body to maintain throughput
    // Accesses every element consecutively but processes two 64-bit chunks per iteration
    for (x = 0; x <= size - 7; x += 2) {
        (((union unaligned_64 *)(&ref_tmp[x]))->l) = (((const union unaligned_64 *)(&top[x - 1]))->l);
        (((union unaligned_64 *)(&ref_tmp[x + 2]))->l) = (((const union unaligned_64 *)(&top[x + 1]))->l);
    }
    // Handle remaining elements if needed (not expanded for simplicity, but loop remains valid)
}
