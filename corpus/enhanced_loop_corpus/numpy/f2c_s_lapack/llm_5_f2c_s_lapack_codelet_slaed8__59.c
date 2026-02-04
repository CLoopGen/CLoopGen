#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *d__;
extern integer *indxq;
extern real *z__;
extern real *dlamda;
extern real *w;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (i__1 >= 1) {
    dlamda[1] = d__[indxq[1]];
    w[1] = z__[indxq[1]];
    for (i__ = 2; i__ <= i__1; ++i__) {
        dlamda[i__] = d__[indxq[i__]];
        w[i__] = z__[indxq[i__]];
    }
} else {
    i__ = 1;
}
}
