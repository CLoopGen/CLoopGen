#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int b_h;
extern int y;
extern  unsigned int color4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with reversed loop order (backward traversal)
    // This changes the memory access pattern to descending indices
    int y;
    uint32_t *dst32_row;
    for (y = b_h - 1; y >= 0; y--) {
        dst32_row = (uint32_t *)(dst + y * stride);
        *dst32_row = color4;
    }
}
