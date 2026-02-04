#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int stride;
extern int size;
extern int k;
extern int t;
extern uint8_t colors[2];
extern int8_t *pglyph;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by transposing the iteration order
    // to write to contiguous locations in `dst` when stride is large.
    // We iterate column-wise but accumulate writes consecutively per row segment.
    uint8_t *d = dst;
    const int8_t *g = pglyph;
    for (k = 0; k < size; k++) {
        for (t = 0; t < size; t++) {
            d[t] = colors[!*g++];
        }
        d += stride; // Move to next row in destination
    }
    pglyph = (int8_t*)g; // Update global pglyph pointer
}
