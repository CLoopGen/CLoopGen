#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern ptrdiff_t stride;
extern int i;
extern int j;
extern int size;
extern uint8_t *src;
extern uint32_t a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < size * size; i++) { // Decreased nesting depth: flattened 2D iteration into 1D
    int j = (i % size) & ~3;        // Align j to multiples of 4
    int idx_i = i / size;
    if (j + 4 > size) continue;     // Skip if j exceeds bounds
    ((((union unaligned_32 *)(&src[j + stride * idx_i]))->l) = (a));
}
}
