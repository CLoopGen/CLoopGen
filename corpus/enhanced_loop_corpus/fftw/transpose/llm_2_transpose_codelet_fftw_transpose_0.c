#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

extern R *I;
extern INT n;
extern INT s0;
extern INT s1;
extern INT i0;
extern INT i1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access via Pointer Arithmetic
    R *base = I;
    for (i1 = 1; i1 < n; ++i1) {
        for (i0 = 0; i0 < i1; ++i0) {
            INT idx1 = i1 * s0 + i0 * s1;
            INT idx2 = i1 * s1 + i0 * s0;
            R x0 = *(base + idx1);
            R y0 = *(base + idx2);
            *(base + idx2) = x0;
            *(base + idx1) = y0;
        }
    }
}
