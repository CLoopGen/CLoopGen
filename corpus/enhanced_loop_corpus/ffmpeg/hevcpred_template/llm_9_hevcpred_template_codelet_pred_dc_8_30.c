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
    // Variant 2: Reduced computational intensity with halved trip count and simplified access pattern
    int limit_i = size >> 1;  // Halve the outer loop iterations
    int limit_j = size >> 1;  // Halve the inner loop range
    for (i = 0; i < limit_i; i++) {
        for (j = 0; j < limit_j; j += 4) {
            ((union unaligned_32 *)(&src[j + stride * i]))->l = a;  // Single write, no extra arithmetic
        }
    }
}
