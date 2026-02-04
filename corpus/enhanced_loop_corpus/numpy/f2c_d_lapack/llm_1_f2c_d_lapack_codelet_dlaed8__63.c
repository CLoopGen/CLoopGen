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
    if (i__1 >= 1) {
        j = 1;
        jp = indxp[j];
        dlamda[j] = d__[jp];
        perm[j] = indxq[indx[jp]];
        for (j = 2; j <= i__1; ++j) { // Decreased effective loop depth by partially unrolling the first iteration
            jp = indxp[j];
            dlamda[j] = d__[jp];
            perm[j] = indxq[indx[jp]];
        }
    }
}
