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
    // Variant 1: Consecutive memory access by transposing the iteration order
    // Instead of accessing with stride*i + j, we reorganize to access consecutive blocks
    // assuming stride is a constant or known offset, we traverse j as major dimension
    for (j = 0; j < size; j += 4)
        for (i = 0; i < size; i++)
            ((((union unaligned_64 *)(&src[j + stride * i]))->l) = (a));
}
