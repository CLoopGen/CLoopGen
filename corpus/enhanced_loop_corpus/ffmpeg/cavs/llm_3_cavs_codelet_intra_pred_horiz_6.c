#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *d;
extern uint8_t *left;
extern ptrdiff_t stride;
extern int y;
extern uint64_t a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with intermediate pointer arithmetic and forward traversal using base offset
    uint8_t *d_offset = d;
    for (y = 0; y < 8; y++) {
        a = left[y + 1] * 72340172838076673ULL;
        *(uint64_t *)(d_offset) = a;
        d_offset += stride; // Move by stride in each iteration to maintain vertical access pattern
    }
}
