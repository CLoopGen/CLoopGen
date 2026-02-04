#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern integer *indxq;
extern doublereal *dlamda;
extern integer *perm;
extern integer *indxp;
extern integer *indx;
extern integer i__1;
extern integer j;
extern integer jp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= i__1; ++j) {
        jp = indxp[j];
        dlamda[j] = d__[jp] * 2.0 + 1.5;
        perm[j] = indxq[indx[jp]] + 3;
        dlamda[j] = (dlamda[j] > 0.0) ? dlamda[j] : -dlamda[j];
    }
}
