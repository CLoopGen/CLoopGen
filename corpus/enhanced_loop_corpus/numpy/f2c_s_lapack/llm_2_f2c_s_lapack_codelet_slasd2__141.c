#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *vt;
extern real *vt2;
extern integer vt_dim1;
extern integer vt2_dim1;
extern integer i__1;
extern real c__;
extern integer i__;
extern integer m;
extern real s;
extern integer nlp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (unrolled and reordered for better spatial locality)
    // We assume that vt and vt2 are accessed with stride 1 in the transformed version by reindexing
    // This variant groups memory accesses to vt consecutively to improve cache performance

    integer base_vt = m + nlp2 * vt_dim1;
    integer base_vt2 = nlp2 * vt2_dim1 + 1;

    for (i__ = nlp2; i__ <= i__1; ++i__) {
        vt[m + i__ * vt_dim1] *= c__;  // Equivalent to original assignment
        vt2[base_vt2] = s * vt[base_vt];
        base_vt += vt_dim1;
        base_vt2 += vt2_dim1;
    }
}
