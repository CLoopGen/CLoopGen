#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *d__;
extern integer *indxq;
extern real *dlamda;
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
        for (j = 2; j <= i__1; ++j) { // Reduce effective nesting by pulling first iteration out
            jp = indxp[j];
            dlamda[j] = d__[jp];
            perm[j] = indxq[indx[jp]];
        }
    } else {
        // Handle empty case
        for (j = 1; j <= i__1; ++j) {
            jp = indxp[j];
            dlamda[j] = d__[jp];
            perm[j] = indxq[indx[jp]];
        }
    }
}
