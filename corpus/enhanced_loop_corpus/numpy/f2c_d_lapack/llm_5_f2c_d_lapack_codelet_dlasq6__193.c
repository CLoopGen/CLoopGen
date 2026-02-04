#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *i0;
extern doublereal *z__;
extern doublereal *dmin__;
extern integer i__1;
extern doublereal d__1;
extern doublereal d__2;
extern doublereal d__;
extern integer j4;
extern doublereal emin;
extern doublereal temp;
extern doublereal safmin;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j4 = *i0 << 2; j4 <= i__1; j4 += 4) {
    z__[j4 - 2] = d__ + z__[j4 - 1];
    if (z__[j4 - 2] != 0. && (safmin * z__[j4 + 1] >= z__[j4 - 2] || safmin * z__[j4 - 2] >= z__[j4 + 1])) {
        z__[j4] = z__[j4 + 1] * (z__[j4 - 1] / z__[j4 - 2]);
        d__ = z__[j4 + 1] * (d__ / z__[j4 - 2]);
    } else {
        if (z__[j4 - 2] == 0.) {
            z__[j4] = 0.;
            d__ = z__[j4 + 1];
            *dmin__ = d__;
            emin = 0.;
        } else {
            temp = z__[j4 + 1] / z__[j4 - 2];
            z__[j4] = z__[j4 - 1] * temp;
            d__ *= temp;
        }
    }
    *dmin__ = ((*dmin__) <= (d__) ? (*dmin__) : (d__));
    d__1 = emin , d__2 = z__[j4];
    emin = ((d__1) <= (d__2) ? (d__1) : (d__2));
}
}
