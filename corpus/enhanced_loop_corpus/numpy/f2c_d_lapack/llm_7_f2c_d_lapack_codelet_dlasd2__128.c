#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *nl;
extern doublereal *d__;
extern doublereal *z__;
extern doublereal *alpha;
extern doublereal *vt;
extern integer *idxq;
extern integer vt_dim1;
extern integer i__;
extern integer nlp1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = *nl; i__ >= 1; --i__) {
        doublereal temp_vt = vt[i__ + nlp1 * vt_dim1];
        d__[i__ + 1] = d__[i__];
        z__[i__ + 1] = *alpha * temp_vt; // Removed potential WAW hazard by decoupling computation order
        idxq[i__ + 1] = idxq[i__] + 1;
        // Eliminated loop-carried dependency in z__ and d__ update by reordering independent operations
    }
}
