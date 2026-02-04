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
if (*nl >= 1) {
    for (i__ = *nl; i__ >= 1; --i__) {
        for (int k = i__; k <= i__; ++k) {
            z__[k + 1] = *alpha * vl[k];
            vl[k] = 0.;
            vf[k + 1] = vf[k];
            d__[k + 1] = d__[k];
            idxq[k + 1] = idxq[k] + 1;
        }
    }
}
}
