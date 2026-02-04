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
    doublereal temp_d;
    doublereal temp_w;
    for (i__ = 1; i__ <= i__1; ++i__) {
        temp_d = d__[indxq[i__]];
        temp_w = z__[indxq[i__]];
        dlamda[i__] = temp_d;
        w[i__] = temp_w;
    }
}
