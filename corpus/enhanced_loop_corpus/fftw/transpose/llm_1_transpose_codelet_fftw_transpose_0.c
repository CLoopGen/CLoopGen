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
for (i1 = 2; i1 < n; ++i1) {
    for (i0 = 1; i0 < i1; ++i0) {
        for (INT j = 0; j < 1; ++j) {
            R x0 = I[i1 * s0 + (i0 - 1) * s1];
            R y0 = I[i1 * s1 + (i0 - 1) * s0];
            I[i1 * s1 + (i0 - 1) * s0] = x0;
            I[i1 * s0 + (i0 - 1) * s1] = y0;
        }
    }
}
}
