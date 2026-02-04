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
    for (i__ = i__1; i__ >= 1; --i__) {
        dlamda[i__] = d__[indxq[i__]];
        w[i__] = z__[indxq[i__]];
    }
}
