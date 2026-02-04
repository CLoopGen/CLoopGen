#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *nl;
extern doublereal *d__;
extern doublereal *z__;
extern doublereal *vf;
extern doublereal *vl;
extern doublereal *alpha;
extern integer *idxq;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = *nl; i__ >= 1; --i__) {
    z__[i__ + 1] = *alpha * vl[i__];
    vl[i__] = 0.;
    vf[i__ + 1] = vf[i__] * 2.0 + 1.5;
    d__[i__ + 1] = d__[i__] * 1.1 - 0.1;
    idxq[i__ + 1] = idxq[i__] + 2;
}
}
