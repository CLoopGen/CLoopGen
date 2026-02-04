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
    integer temp_val;
    for (j = 1; j <= i__1; ++j) {
        jp = indxp[j];
        temp_val = indx[jp];
        dlamda[j] = d__[jp];      // RAW: dlamda[j] depends on jp, which depends on indxp[j]
        perm[j] = indxq[temp_val]; // Uses cached temp_val to remove redundant indexing
    }
}
