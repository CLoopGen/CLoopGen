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
    for (i__ = *nl; i__ >= 1; --i__) {
        z__[i__ + 1] = *alpha * vl[i__];
        vl[i__] = 0.F;
        if (i__ % 2 == 0) {
            vf[i__ + 1] = vf[i__];
        } else {
            vf[i__ + 1] = 0.F;
        }
        d__[i__ + 1] = d__[i__];
        idxq[i__ + 1] = idxq[i__] + 1;
    }
}
