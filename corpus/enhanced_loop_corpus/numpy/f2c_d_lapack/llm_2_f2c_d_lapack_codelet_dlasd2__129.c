#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *z__;
extern doublereal *beta;
extern doublereal *vt;
extern integer vt_dim1;
extern integer i__1;
extern integer i__;
extern integer nlp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reindexing to access contiguous elements in z__ and vt
    // Assuming vt is stored in column-major order, we modify the access pattern to traverse consecutive memory locations
    integer base_index = nlp2 * (vt_dim1 + 1);
    for (i__ = nlp2; i__ <= i__1; ++i__) {
        z__[i__] = *beta * vt[base_index++];
    }
}
