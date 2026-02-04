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
    // Variant 1: Consecutive memory access with pre-computed offset and reversed loop order
    uint64_t *d64 = (uint64_t *)d;
    for (y = 7; y >= 0; y--) {
        a = left[y + 1] * 72340172838076673ULL;
        d64[y * (stride / sizeof(uint64_t))] = a;
    }
}
