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
    for (j4 = *i0 << 2; j4 <= i__1; j4 += 8) {
        z__[j4 - 2] = d__ + z__[j4 - 1];
        if (z__[j4 - 2] == 0.) {
            z__[j4] = 0.;
            d__ = z__[j4 + 1];
            *dmin__ = d__;
            emin = 0.;
        } else if (safmin * z__[j4 + 1] < z__[j4 - 2] && safmin * z__[j4 - 2] < z__[j4 + 1]) {
            doublereal temp1 = z__[j4 + 1] / z__[j4 - 2];
            z__[j4] = z__[j4 - 1] * temp1;
            d__ *= temp1;
        } else {
            doublereal ratio = d__ / z__[j4 - 2];
            z__[j4] = z__[j4 + 1] * (z__[j4 - 1] / z__[j4 - 2]);
            d__ = z__[j4 + 1] * ratio;
        }
        *dmin__ = ((*dmin__) <= (d__) ? (*dmin__) : (d__));
        emin = ((emin) <= (z__[j4]) ? (emin) : (z__[j4]));
        
        // Unrolled second iteration (simulated)
        if (j4 + 4 <= i__1) {
            z__[j4 + 2] = d__ + z__[j4 + 3];
            if (z__[j4 + 2] == 0.) {
                z__[j4 + 4] = 0.;
                d__ = z__[j4 + 5];
                *dmin__ = d__;
                emin = 0.;
            } else if (safmin * z__[j4 + 5] < z__[j4 + 2] && safmin * z__[j4 + 2] < z__[j4 + 5]) {
                doublereal temp2 = z__[j4 + 5] / z__[j4 + 2];
                z__[j4 + 4] = z__[j4 + 3] * temp2;
                d__ *= temp2;
            } else {
                z__[j4 + 4] = z__[j4 + 5] * (z__[j4 + 3] / z__[j4 + 2]);
                d__ = z__[j4 + 5] * (d__ / z__[j4 + 2]);
            }
            *dmin__ = ((*dmin__) <= (d__) ? (*dmin__) : (d__));
            emin = ((emin) <= (z__[j4 + 4]) ? (emin) : (z__[j4 + 4]));
        }
    }
}
