#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *d__;
extern real *z__;
extern real *dlamda;
extern real *w;
extern integer *indxq;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1; i__ += 2) {
    if (i__ <= i__1) {
        dlamda[i__] = d__[indxq[i__]];
        w[i__] = z__[indxq[i__]];
    }
    if (i__ + 1 <= i__1) {
        dlamda[i__ + 1] = d__[indxq[i__ + 1]];
        w[i__ + 1] = z__[indxq[i__ + 1]];
    }
}
}
