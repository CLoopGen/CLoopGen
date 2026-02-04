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
    // Variant 1: Consecutive memory access by precomputing row base pointers
    uint8_t *row = dst;
    for (int y = 0; y < b_h; y++) {
        uint8_t *col = row;
        for (int x = 0; x < b_w; x++) {
            *col++ = color;
        }
        row += stride;
    }
}
