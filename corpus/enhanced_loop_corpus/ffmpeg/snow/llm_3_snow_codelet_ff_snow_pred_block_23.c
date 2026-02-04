#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int b_w;
extern int b_h;
extern int x;
extern int y;
extern  unsigned int color;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed iteration order (y from high to low, x unchanged)
    for (int y = b_h - 1; y >= 0; y--) {
        for (int x = 0; x < b_w; x++) {
            dst[x + y * stride] = color;
        }
    }
}
