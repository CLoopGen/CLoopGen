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
    // Variant 1: Consecutive memory access by reordering computation to access 's' with consecutive indices where possible
    // Assuming u[x] values are clustered, we sort or rearrange access based on u[x], but since we cannot reorder arbitrarily,
    // we simulate a strided and more cache-friendly access by processing in chunks if u and v have locality.
    // Instead, we unroll the loop by 2 for better memory prefetching and consecutive pattern exposure.

    int x = 0;
    for (; x + 1 < width; x += 2) {
        d[x]   = s[v[x] * in_linesize + u[x]];
        d[x+1] = s[v[x+1] * in_linesize + u[x+1]];
    }
    for (; x < width; x++) {
        d[x] = s[v[x] * in_linesize + u[x]];
    }
}
