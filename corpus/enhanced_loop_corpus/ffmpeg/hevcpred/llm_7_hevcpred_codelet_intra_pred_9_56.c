#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern int i;
extern int size;
extern uint16_t *left;
extern uint64_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_accum = 0;
    for (i = 0; i < (size); i += 4) {
        local_accum += pix; // Eliminate direct loop-carried WAW/RW dependencies by using local accumulation
        (((union unaligned_64 *)(left + i))->l) = local_accum;
    }
    // Final write to memory with accumulated value (side effect outside loop)
    if (size > 0) {
        ((union unaligned_64 *)(left + 0))->l = local_accum;
    }
}
