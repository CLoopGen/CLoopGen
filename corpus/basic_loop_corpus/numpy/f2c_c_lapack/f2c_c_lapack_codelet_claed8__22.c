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
for (i__ = 1; i__ <= i__1; ++i__) {
    d__[i__] = dlamda[indx[i__]];
    z__[i__] = w[indx[i__]];
}

}
