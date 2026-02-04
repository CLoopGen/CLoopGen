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
ptrdiff_t base = *i0 << 2;
for (integer k = 0; base + k <= i__1; k += 4) {
    integer j = base + k;
    z__[j - 2] = d__ + z__[j - 1];
    temp = z__[j + 1] / z__[j - 2];
    d__ = d__ * temp - *tau;
    *dmin__ = ((*dmin__) <= (d__) ? (*dmin__) : (d__));
    z__[j] = z__[j - 1] * temp;
    d__1 = z__[j];
    emin = ((d__1) <= (emin) ? (d__1) : (emin));
}
}
