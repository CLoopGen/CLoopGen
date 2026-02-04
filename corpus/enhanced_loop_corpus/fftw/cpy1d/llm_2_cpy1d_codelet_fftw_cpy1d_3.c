#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

extern R *I;
extern R *O;
extern INT n0;
extern INT is0;
extern INT os0;
extern INT vl;
extern INT i0;
extern INT v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by swapping loop order for spatial locality
    for (v = 0; v < vl; ++v)
        for (i0 = 0; i0 < n0; ++i0) {
            R x0 = I[i0 * is0 + v];
            O[i0 * os0 + v] = x0;
        }
}
