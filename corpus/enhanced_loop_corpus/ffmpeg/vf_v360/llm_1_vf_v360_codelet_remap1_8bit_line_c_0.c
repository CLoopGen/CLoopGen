#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern ptrdiff_t in_linesize;
extern  int16_t * u;
extern  int16_t * v;
extern  uint8_t * s;
extern uint8_t *d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Decreased loop nesting depth by unrolling the loop twice and reducing iterations (assuming width is even)
    int x = 0;
    for (; x < width - 1; x += 2) {
        d[x] = s[v[x] * in_linesize + u[x]];
        d[x+1] = s[v[x+1] * in_linesize + u[x+1]];
    }
    // Handle remaining element if width is odd
    if (x < width) {
        d[x] = s[v[x] * in_linesize + u[x]];
    }
}
