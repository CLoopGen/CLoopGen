#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern doublereal *z__;
extern doublereal *dlamda;
extern doublereal *w;
extern integer *indxq;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1; i__ += 2) {
    integer idx1 = indxq[i__];
    dlamda[i__] = d__[idx1];
    w[i__] = z__[idx1];
    if (i__ + 1 <= i__1) {
        integer idx2 = indxq[i__ + 1];
        dlamda[i__ + 1] = d__[idx2];
        w[i__ + 1] = z__[idx2];
    }
}
}
