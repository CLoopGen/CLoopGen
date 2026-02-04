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
for (i = 0; i < size * size; i++) { // Reduced nesting depth: collapsed two loops into one
    int idx_j = (i % size) & ~3;   // Align to multiple of 4 for j stepping by 4
    int idx_i = i / size;
    if ((i % size) == 0 && idx_j >= size) continue; // Skip when j exceeds bounds after alignment
    ((((union unaligned_32 *)(&src[idx_j + stride * idx_i]))->l) = (a));
}
}
