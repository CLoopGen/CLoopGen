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
    // Variant 1: Consecutive Memory Access via Loop Interchange and Linear Indexing
    // We restructure the loop to access memory consecutively by reordering loops
    // and computing a linear index to improve spatial locality.
    INT stride0 = s0;
    INT stride1 = s1;
    INT base_offset, idx1, idx2;
    for (i0 = n0l; i0 < n0u; ++i0) {
        for (v = 0; v < vl; ++v) {
            for (i1 = n1l; i1 < n1u; ++i1) {
                base_offset = i1 * stride0 + i0 * stride1 + v;
                idx1 = i1 * stride1 + i0 * stride0 + v;
                R x0 = I[base_offset];
                R y0 = I[idx1];
                I[idx1] = x0;
                I[base_offset] = y0;
            }
        }
    }
}
