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
    real temp1, temp2, temp3;
    for (j4 = *i0 << 2; j4 <= i__1; j4 += 4) {
        z__[j4 - 2] = d__ + z__[j4 - 1];
        temp1 = z__[j4 + 1] / z__[j4 - 2];
        temp2 = d__ * temp1 - *tau;
        *dmin__ = (doublereal)((*dmin__) <= (temp2) ? (*dmin__) : (temp2));
        z__[j4] = z__[j4 - 1] * temp1;
        temp3 = z__[j4];
        emin = (doublereal)((temp3) <= (emin) ? (temp3) : (emin));
        d__ = temp2;
    }
}
