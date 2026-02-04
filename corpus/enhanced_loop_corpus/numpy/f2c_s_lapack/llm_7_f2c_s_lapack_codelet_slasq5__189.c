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
    real local_d = d__;
    real local_emin = emin;
    for (j4 = *i0 << 2; j4 <= i__1; j4 += 4) {
        z__[j4 - 2] = local_d + z__[j4 - 1];
        temp = z__[j4 + 1] / z__[j4 - 2];
        local_d = local_d * temp - *tau;
        z__[j4] = z__[j4 - 1] * temp;
        r__1 = z__[j4];
        local_emin = (doublereal)((r__1) <= (local_emin) ? (r__1) : (local_emin));
    }
    d__ = local_d;
    emin = local_emin;
    *dmin__ = (doublereal)((*dmin__) <= (local_d) ? (*dmin__) : (local_d));
}
