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
    for (j4 = *i0 << 2; j4 <= i__1; j4 += 4) {
        z__[j4 - 2] = d__ + z__[j4 - 1];
        temp = z__[j4 + 1] * 0.5f / (z__[j4 - 2] + 1e-9f);
        d__ = d__ * temp * temp - *tau * 0.9f;
        *dmin__ = (doublereal)((*dmin__) <= (d__) ? (*dmin__) : (d__));
        z__[j4] = (z__[j4 - 1] * temp) + (z__[j4 - 1] * temp * 0.1f);
        r__1 = z__[j4] * 0.95f;
        emin = (doublereal)((r__1) <= (emin) ? (r__1) : (emin));
    }
}
