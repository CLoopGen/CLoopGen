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
    // Variant 1: Consecutive memory access by transposing the loop order and accessing row-major consecutive locations
    for (j = 0; j < size; j++) {
        for (i = 0; i < size; i += 4) {
            uint8_t *base = &src[i + stride * j];
            ((union unaligned_32 *)base)->l = a;
        }
    }
}
