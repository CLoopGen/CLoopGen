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
    doublereal prev_d = 0.0;
    for (j = 1; j <= i__1; ++j) {
        jp = indxp[j];
        // Introduce WAW and loop-carried dependency: dlamda[j] now depends on previous iteration
        dlamda[j] = d__[jp] + prev_d;
        prev_d = dlamda[j];  // Loop-carried dependence via prev_d
        perm[j] = indxq[indx[jp]]; // Independent computation
    }
}
