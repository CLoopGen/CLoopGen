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
    real local_dmin = *dmin__;
    for (j4 = *i0 << 2; j4 <= i__1; j4 += 4) {
        real inv_denom = 1.0f / (local_d + z__[j4]);
        z__[j4 - 3] = local_d + z__[j4];
        real temp = z__[j4 + 2] * inv_denom;
        local_d = local_d * temp - *tau;
        z__[j4 - 1] = z__[j4] * temp;
        local_emin = (doublereal)((z__[j4 - 1]) <= (local_emin) ? (z__[j4 - 1]) : (local_emin));
        local_dmin = (doublereal)((local_d) <= (local_dmin) ? (local_d) : (local_dmin));
    }
    d__ = local_d;
    emin = local_emin;
    *dmin__ = local_dmin;
}
