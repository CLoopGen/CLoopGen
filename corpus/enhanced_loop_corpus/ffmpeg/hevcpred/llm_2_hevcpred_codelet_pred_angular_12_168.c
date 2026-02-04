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
    // Variant 1: Strided memory access with increased stride (stride of 8 instead of 4)
    // This changes the access pattern to skip more elements each iteration, reducing total iterations
    for (x = 0; x <= size; x += 8) {
        if (x <= size - 7) {  // Ensure we don't go out of bounds
            (((union unaligned_64 *)(&ref_tmp[x]))->l) = (((const union unaligned_64 *)(&top[x - 1]))->l);
        }
    }
}
