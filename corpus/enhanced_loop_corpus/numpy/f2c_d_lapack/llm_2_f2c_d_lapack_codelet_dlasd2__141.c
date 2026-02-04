#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *vt;
extern doublereal *vt2;
extern integer vt_dim1;
extern integer vt2_dim1;
extern integer i__1;
extern doublereal c__;
extern integer i__;
extern integer m;
extern doublereal s;
extern integer nlp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Reorganize array accesses to be consecutive by precomputing base indices
    integer base_vt = m;
    integer base_vt2 = 1;
    for (i__ = nlp2; i__ <= i__1; ++i__) {
        integer idx_vt = base_vt + i__ * vt_dim1;
        integer idx_vt2 = base_vt2 + i__ * vt2_dim1;
        vt2[idx_vt2] = s * vt[idx_vt];
        vt[idx_vt] = c__ * vt[idx_vt];
    }
}
