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
    // Variant 2: Strided Memory Access with Explicit Stride Accumulation
    // Instead of recalculating indices from scratch, we use incremental updates
    // with pointer arithmetic and fixed strides to simulate a strided access pattern.
    R *base_I = I;
    INT offset0 = s0;
    INT offset1 = s1;
    INT step_v = 1;
    INT total_i0_steps = n0u - n0l;
    INT total_i1_steps = n1u - n1l;

    INT i1_start_offset = n1l * offset0;
    INT i0_start_offset = n0l * offset1;

    for (INT di1 = 0; di1 < total_i1_steps; ++di1) {
        INT abs_i1 = n1l + di1;
        INT base1 = i1_start_offset + di1 * offset0;
        for (INT di0 = 0; di0 < total_i0_steps; ++di0) {
            INT abs_i0 = n0l + di0;
            INT base2 = i0_start_offset + di0 * offset1;
            for (v = 0; v < vl; ++v) {
                INT idx1 = base1 + base2 + v;
                INT idx2 = abs_i1 * offset1 + abs_i0 * offset0 + v;
                R x0 = base_I[idx1];
                R y0 = base_I[idx2];
                base_I[idx2] = x0;
                base_I[idx1] = y0;
            }
        }
    }
}
