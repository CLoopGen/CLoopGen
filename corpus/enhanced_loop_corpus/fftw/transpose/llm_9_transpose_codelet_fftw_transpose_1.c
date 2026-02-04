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
for (i1 = 1; i1 < n; i1 += 2) {
    for (i0 = 0; i0 < i1 && (i1 + 1) < n; ++i0) {
        R x0 = I[i1 * s0 + i0 * s1];
        R x1 = I[i1 * s0 + i0 * s1 + 1];
        R y0 = I[i1 * s1 + i0 * s0];
        R y1 = I[i1 * s1 + i0 * s0 + 1];
        I[i1 * s1 + i0 * s0] = x0;
        I[i1 * s1 + i0 * s0 + 1] = x1;
        I[i1 * s0 + i0 * s1] = y0;
        I[i1 * s0 + i0 * s1 + 1] = y1;

        // Second iteration unrolled: operate on i1+1 if valid
        if (i1 + 1 < n) {
            R z0 = I[(i1 + 1) * s0 + i0 * s1];
            R z1 = I[(i1 + 1) * s0 + i0 * s1 + 1];
            R w0 = I[(i1 + 1) * s1 + i0 * s0];
            R w1 = I[(i1 + 1) * s1 + i0 * s0 + 1];
            I[(i1 + 1) * s1 + i0 * s0] = z0;
            I[(i1 + 1) * s1 + i0 * s0 + 1] = z1;
            I[(i1 + 1) * s0 + i0 * s1] = w0;
            I[(i1 + 1) * s0 + i0 * s1 + 1] = w1;
        }
    }
}
}
