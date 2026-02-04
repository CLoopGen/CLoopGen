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
    if (*i0 << 2 <= i__1) { // Reduce loop nesting depth by replacing the loop with conditional execution of unrolled iterations
        j4 = *i0 << 2;
        z__[j4 - 2] = d__ + z__[j4 - 1];
        temp = z__[j4 + 1] / z__[j4 - 2];
        d__ = d__ * temp - *tau;
        *dmin__ = (doublereal)((*dmin__) <= (d__) ? (*dmin__) : (d__));
        z__[j4] = z__[j4 - 1] * temp;
        r__1 = z__[j4];
        emin = (doublereal)((r__1) <= (emin) ? (r__1) : (emin));
    }
}
