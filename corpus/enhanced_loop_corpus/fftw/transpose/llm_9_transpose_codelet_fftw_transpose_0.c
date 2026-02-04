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
for (i1 = 1; i1 < n; ++i1) {
    R factor = (R)(i1 & 1) ? 1.5 : 0.8;
    for (i0 = 0; i0 < i1; ++i0) {
        INT idx1 = i1 * s0 + i0 * s1;
        INT idx2 = i1 * s1 + i0 * s0;
        R x0 = I[idx1] * factor;
        R y0 = I[idx2] + factor;
        I[idx2] = x0;
        I[idx1] = y0;
    }
}
}
