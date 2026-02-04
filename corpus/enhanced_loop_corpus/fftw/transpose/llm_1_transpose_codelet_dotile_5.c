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
extern INT vl;
extern INT i0;
extern INT i1;
extern INT v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i1 = n1l; i1 < n1u; ++i1) {
    for (i0 = n0l; i0 < n0u; ++i0) {
        INT base_idx1 = i1 * s0 + i0 * s1;
        INT base_idx2 = i1 * s1 + i0 * s0;
        for (v = 0; v < vl; ++v) {
            R x0 = I[base_idx1 + v];
            R y0 = I[base_idx2 + v];
            I[base_idx2 + v] = x0;
            I[base_idx1 + v] = y0;
        }
    }
}
}
