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
for (j4 = (*i0 << 2) + 2; j4 <= i__1; j4 += 4) {
    doublereal t1 = z__[j4] + d__;
    z__[j4 - 3] = t1;
    doublereal inv = 1.0 / t1;
    doublereal t2 = z__[j4 + 2] * inv;
    d__ = d__ * t2 - *tau;
    *dmin__ = ((*dmin__) <= (d__) ? (*dmin__) : (d__));
    z__[j4 - 1] = z__[j4] * t2;
    emin = ((z__[j4 - 1]) <= (emin) ? (z__[j4 - 1]) : (emin));
}
}
