#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *i0;
extern doublereal *z__;
extern doublereal *tau;
extern doublereal *dmin__;
extern integer i__1;
extern doublereal d__1;
extern doublereal d__;
extern integer j4;
extern doublereal emin;
extern doublereal temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j4 = *i0 << 2; j4 <= i__1; j4 += 4) {
    ptrdiff_t idx = j4 - 2;
    z__[idx] = d__ + z__[idx + 1];
    temp = z__[idx + 3] / z__[idx];
    d__ = d__ * temp - *tau;
    *dmin__ = ((*dmin__) <= (d__) ? (*dmin__) : (d__));
    z__[idx + 2] = z__[idx + 1] * temp;
    d__1 = z__[idx + 2];
    emin = ((d__1) <= (emin) ? (d__1) : (emin));
}
}
