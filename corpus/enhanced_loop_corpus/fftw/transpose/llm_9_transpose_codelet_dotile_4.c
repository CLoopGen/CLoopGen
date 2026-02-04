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
for (i1 = n1l; i1 < n1u; i1 += 2) {
    for (i0 = n0l; i0 < n0u; i0 += 2) {
        if (i1 + 1 < n1u && i0 + 1 < n0u) {
            INT idx1_00 = i1 * s0 + i0 * s1;
            INT idx1_01 = i1 * s0 + (i0 + 1) * s1;
            INT idx1_10 = (i1 + 1) * s0 + i0 * s1;
            INT idx1_11 = (i1 + 1) * s0 + (i0 + 1) * s1;
            INT idx2_00 = i1 * s1 + i0 * s0;
            INT idx2_01 = i1 * s1 + (i0 + 1) * s0;
            INT idx2_10 = (i1 + 1) * s1 + i0 * s0;
            INT idx2_11 = (i1 + 1) * s1 + (i0 + 1) * s0;

            R x00 = I[idx1_00], x01 = I[idx1_01];
            R x10 = I[idx1_10], x11 = I[idx1_11];
            R y00 = I[idx2_00], y01 = I[idx2_01];
            R y10 = I[idx2_10], y11 = I[idx2_11];

            I[idx2_00] = x00; I[idx2_01] = x01;
            I[idx2_10] = x10; I[idx2_11] = x11;
            I[idx1_00] = y00; I[idx1_01] = y01;
            I[idx1_10] = y10; I[idx1_11] = y11;

            I[idx2_00 + 1] = x00 + 1.0; 
            I[idx2_01 + 1] = x01 + 1.0; 
            I[idx1_00 + 1] = y00 + 1.0; 
            I[idx1_01 + 1] = y01 + 1.0; 
        }
    }
}
}
