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
        z__[j4 - 2] = d__ + z__[j4 - 1];
        temp = z__[j4 + 1] / z__[j4 - 2];
        d__ = d__ * temp - *tau;
        if (d__ < *dmin__) {
            *dmin__ = d__;
        }
        z__[j4] = z__[j4 - 1] * temp;
        if (z__[j4] < emin) {
            emin = z__[j4];
        }
    }
}
