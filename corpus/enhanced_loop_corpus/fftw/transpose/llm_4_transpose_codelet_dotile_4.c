#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

extern INT n0l;
extern INT n0u;
extern INT n1l;
extern INT n1u;
extern R *I;
extern INT s0;
extern INT s1;
extern INT i0;
extern INT i1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i1 = n1l; i1 < n1u; ++i1) {
    for (i0 = n0l; i0 < n0u; ++i0) {
        if ((i1 + i0) % 2 == 0) {
            R x0 = I[i1 * s0 + i0 * s1];
            R x1 = I[i1 * s0 + i0 * s1 + 1];
            R y0 = I[i1 * s1 + i0 * s0];
            R y1 = I[i1 * s1 + i0 * s0 + 1];
            I[i1 * s1 + i0 * s0] = x0;
            I[i1 * s1 + i0 * s0 + 1] = x1;
            I[i1 * s0 + i0 * s1] = y0;
            I[i1 * s0 + i0 * s1 + 1] = y1;
        }
    }
}
}
