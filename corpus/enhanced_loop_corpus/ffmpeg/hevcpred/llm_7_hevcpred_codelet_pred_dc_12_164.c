#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern ptrdiff_t stride;
extern int i;
extern int j;
extern int size;
extern uint16_t *src;
extern uint64_t a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_accumulator = 0;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j += 4) {
            uint64_t current_val = ((union unaligned_64 *)(&src[j + stride * i]))->l;
            local_accumulator += current_val; // Introduce RAW dependency on memory reads
        }
    }
    // Break original write semantics but maintain valid computation
    // Use final accumulator to update one location, removing per-iteration side effects
    if (size > 0) {
        (((union unaligned_64 *)(&src[0]))->l) = local_accumulator ^ a;
    }
}
