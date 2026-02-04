#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef double doublereal;

extern integer *i0;
extern real *z__;
extern real *tau;
extern real *dmin__;
extern integer i__1;
extern real r__1;
extern real d__;
extern integer j4;
extern real emin;
extern real temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j4 = (*i0 << 2) + 4; j4 <= i__1 + 4; j4 += 4) {
    integer base = j4 - 4;
    z__[base - 2] = d__ + z__[base];
    temp = z__[base + 2] / z__[base - 2];
    d__ = d__ * temp - *tau;
    *dmin__ = (doublereal)((*dmin__) <= (d__) ? (*dmin__) : (d__));
    z__[base] = z__[base] * temp;
    r__1 = z__[base];
    emin = (doublereal)((r__1) <= (emin) ? (r__1) : (emin));
}
}
