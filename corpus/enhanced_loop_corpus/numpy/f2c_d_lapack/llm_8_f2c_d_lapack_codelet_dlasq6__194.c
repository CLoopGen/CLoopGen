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
        z__[j4 - 3] = d__ + z__[j4];
        if (z__[j4 - 3] == 0.) {
            z__[j4 - 1] = 0.;
            d__ = z__[j4 + 2];
            *dmin__ = d__;
            emin = 0.;
        } else if (safmin * z__[j4 + 2] < z__[j4 - 3] && safmin * z__[j4 - 3] < z__[j4 + 2]) {
            temp = z__[j4 + 2] / z__[j4 - 3];
            z__[j4 - 1] = z__[j4] * temp;
            d__ *= temp;
        } else {
            z__[j4 - 1] = z__[j4 + 2] * (z__[j4] / z__[j4 - 3]);
            d__ = z__[j4 + 2] * (d__ / z__[j4 - 3]);
        }
        // Introduce artificial WAW and WAR: reorder updates with temporary
        doublereal new_dmin = ((*dmin__) <= (d__)) ? (*dmin__) : (d__);
        doublereal new_emin = (emin <= z__[j4 - 1]) ? emin : z__[j4 - 1];
        emin = new_emin;
        *dmin__ = new_dmin;
    }
}
