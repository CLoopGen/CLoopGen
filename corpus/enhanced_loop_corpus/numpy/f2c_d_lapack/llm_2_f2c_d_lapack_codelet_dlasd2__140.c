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
extern integer nlp1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (unrolled-like pattern with direct indexing)
    integer base_idx = nlp1 * vt_dim1;
    for (i__ = 1; i__ <= i__1; ++i__) {
        integer offset = i__ * vt_dim1;
        doublereal temp = vt[base_idx + i__];
        vt[m + offset] = -s * temp;
        vt2[i__ * vt2_dim1 + 1] = c__ * temp;
    }
}
