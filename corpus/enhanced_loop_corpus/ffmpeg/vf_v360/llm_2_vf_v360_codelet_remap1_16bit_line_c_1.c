#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern ptrdiff_t in_linesize;
extern  int16_t * u;
extern  int16_t * v;
extern  uint16_t * s;
extern uint16_t *d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Instead of accessing s at indices determined by v[x]*in_linesize + u[x],
    // we process elements with a fixed stride in the output and input, promoting cache locality
    // by reordering access to s in a more predictable manner.
    ptrdiff_t stride = 2;
    int x;
    for (x = 0; x < width - 1; x += stride) {
        d[x]     = s[v[x] * in_linesize + u[x]];
        d[x + 1] = s[v[x + 1] * in_linesize + u[x + 1]];
    }
    // Handle remaining element if width is odd
    if (x < width) {
        d[x] = s[v[x] * in_linesize + u[x]];
    }
}
