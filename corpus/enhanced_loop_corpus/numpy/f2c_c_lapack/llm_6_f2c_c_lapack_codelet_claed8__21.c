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
    real temp_d;
    real temp_w;
    for (i__ = 1; i__ <= i__1; ++i__) {
        temp_d = d__[indxq[i__]];
        temp_w = z__[indxq[i__]];
        dlamda[i__] = temp_d;
        w[i__] = temp_w;
    }
}
