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
extern integer nlp1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (unrolled with stride-1 access)
    // We assume vt and vt2 are accessed in a more cache-friendly, consecutive manner by reordering computation.
    // This variant assumes that vt_dim1 and vt2_dim1 are strides, and we simulate processing elements consecutively
    // by precomputing base indices to promote linear memory traversal.

    integer idx_vt_nlp1_base = nlp1 * vt_dim1;
    integer idx_vt_m_base = m * vt_dim1;
    integer idx_vt2_base = vt2_dim1;

    for (i__ = 1; i__ <= i__1; ++i__) {
        real val = vt[idx_vt_nlp1_base + i__];
        vt[idx_vt_m_base + i__] = -s * val;
        vt2[i__ * idx_vt2_base + 1] = c__ * val;
    }
}
