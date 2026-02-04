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
extern INT vl;
extern INT i0;
extern INT i1;
extern INT v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i1 = 1; i1 < n; ++i1) {
    for (i0 = 0; i0 < i1; ++i0) {
        INT base_idx_1 = i1 * s0 + i0 * s1;
        INT base_idx_2 = i1 * s1 + i0 * s0;
        for (v = 0; v < vl; ++v) {
            R x0 = I[base_idx_1 + v];
            R y0 = I[base_idx_2 + v];
            I[base_idx_2 + v] = x0;
            I[base_idx_1 + v] = y0;
        }
    }
}
}
