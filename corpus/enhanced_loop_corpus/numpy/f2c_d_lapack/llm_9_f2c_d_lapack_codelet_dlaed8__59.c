#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern integer *indxq;
extern doublereal *z__;
extern doublereal *dlamda;
extern doublereal *w;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 2; i__ <= i__1; i__ += 2) { // Reduced trip count by half, stride-2 iteration
        dlamda[i__]   = d__[indxq[i__]];
        w[i__]       = z__[indxq[i__]];
        dlamda[i__-1] = d__[indxq[i__-1]];
        w[i__-1]     = z__[indxq[i__-1]];
    }
    if (i__1 > 0 && i__1 % 2 == 1) { // Handle odd-sized case
        dlamda[i__1] = d__[indxq[i__1]];
        w[i__1] = z__[indxq[i__1]];
    }
}
