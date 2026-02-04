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
    uint64_t local_accum = 0;
    for (i = 0; i < size; i++) {
        local_accum = a; // Remove loop-carried dependency by making accumulation per-row
        for (j = 0; j < size; j += 4) {
            local_accum ^= (uint64_t)(j + i); // Add temporary computation not affecting memory directly
            ((((union unaligned_64 *)(&src[(j) + stride * (i)]))->l) = local_accum);
        }
        a = local_accum; // Only final update to 'a' after each row, breaking per-element dependency
    }
}
