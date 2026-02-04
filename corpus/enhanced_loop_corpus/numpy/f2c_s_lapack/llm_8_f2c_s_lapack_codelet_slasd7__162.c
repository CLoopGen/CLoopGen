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
for (i__ = 1; i__ <= *nl; ++i__) { // Reverse loop direction to eliminate loop-carried dependence in backward direction
    d__[i__ + 1] = d__[i__];
    vf[i__ + 1] = vf[i__];
    idxq[i__ + 1] = idxq[i__] + 1;
    z__[i__ + 1] = *alpha * vl[i__];
    vl[i__] = 0.F;
}
}
