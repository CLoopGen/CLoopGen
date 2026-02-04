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
            R sum_x = 0.0, sum_y = 0.0;
            for (v = 0; v < vl; ++v) {
                INT idx1 = i1 * s0 + i0 * s1 + v;
                INT idx2 = i1 * s1 + i0 * s0 + v;
                sum_x += I[idx1];
                sum_y += I[idx2];
            }
            for (v = 0; v < vl; ++v) {
                INT idx1 = i1 * s0 + i0 * s1 + v;
                INT idx2 = i1 * s1 + i0 * s0 + v;
                R x0 = I[idx1];
                R y0 = I[idx2];
                I[idx1] = y0;
                I[idx2] = x0;
            }
        }
    }
}
