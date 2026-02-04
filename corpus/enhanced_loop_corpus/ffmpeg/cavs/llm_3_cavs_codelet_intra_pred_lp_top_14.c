#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *d;
extern uint8_t *top;
extern ptrdiff_t stride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed loop order (column-major processing)
    for (x = 0; x < 8; x++) {
        ptrdiff_t offset = (x + 1); // Precompute horizontal offset into top
        for (y = 0; y < 8; y++) {
            d[y * stride + x] = ((top[offset - 1] + 2 * top[offset] + top[offset + 1] + 2) >> 2);
        }
    }
}
