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
    z__[i__ + 1] = *alpha * vt[i__ + nlp1 * vt_dim1];
    if (d__[i__] >= 0.0) {
        d__[i__ + 1] = d__[i__];
        idxq[i__ + 1] = idxq[i__] + 1;
    } else {
        d__[i__ + 1] = 0.0;
        idxq[i__ + 1] = idxq[i__];
    }
}
}
