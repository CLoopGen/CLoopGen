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
extern integer *indx;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 1; i__ <= i__1; i__ += 2) {
        integer idx1 = indx[i__];
        d__[i__] = dlamda[idx1];
        z__[i__] = w[idx1];
        if (i__ + 1 <= i__1) {
            integer idx2 = indx[i__ + 1];
            d__[i__ + 1] = dlamda[idx2];
            z__[i__ + 1] = w[idx2];
        }
    }
}
