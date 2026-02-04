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
INT i;
for (i = 0; i < (n1u - n1l) * (n0u - n0l); ++i) {
    i1 = n1l + i / (n0u - n0l);
    i0 = n0l + i % (n0u - n0l);
    R x0 = I[i1 * s0 + i0 * s1];
    R y0 = I[i1 * s1 + i0 * s0];
    I[i1 * s1 + i0 * s0] = x0;
    I[i1 * s0 + i0 * s1] = y0;
}
}
