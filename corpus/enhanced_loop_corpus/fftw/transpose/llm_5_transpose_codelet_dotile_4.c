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
        R x0, x1, y0, y1;
        INT idx1 = i1 * s0 + i0 * s1;
        INT idx2 = i1 * s1 + i0 * s0;

        if (abs(idx1 - idx2) > 1) {
            x0 = I[idx1];
            x1 = I[idx1 + 1];
            y0 = I[idx2];
            y1 = I[idx2 + 1];
            I[idx2] = x0;
            I[idx2 + 1] = x1;
            I[idx1] = y0;
            I[idx1 + 1] = y1;
        } else {
            // Skip swap to avoid potential overlap or aliasing issues
            continue;
        }
    }
}
}
