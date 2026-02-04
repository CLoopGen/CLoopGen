#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *nl;
extern real *d__;
extern real *z__;
extern real *vf;
extern real *vl;
extern real *alpha;
extern integer *idxq;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Remapping
    // Use an auxiliary array to define indirect access order (simulated via reversed index mapping)
    // Since we cannot introduce new global arrays, simulate indirect indexing using arithmetic
    // Map logical iteration index to physical array index in reverse-scattered manner
    // Simulate permutation: p(i) = (*nl - i__ + 1), accessing arrays indirectly

    for (i__ = *nl; i__ >= 1; --i__) {
        integer phys_idx = *nl - i__ + 1; // Reverse mapping: indirect access pattern
        
        z__[phys_idx + 1] = *alpha * vl[phys_idx];
        vl[phys_idx] = 0.F;
        vf[phys_idx + 1] = vf[phys_idx];
        d__[phys_idx + 1] = d__[phys_idx];
        idxq[phys_idx + 1] = idxq[phys_idx] + 1;
    }
}
