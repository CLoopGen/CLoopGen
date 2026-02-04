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
doublereal local_dmin = *dmin__;
doublereal local_emin = emin;
for (j4 = *i0 << 2; j4 <= i__1; j4 += 4) {
    z__[j4 - 2] = d__ + z__[j4 - 1];
    if (z__[j4 - 2] == 0.) {
        z__[j4] = 0.;
        d__ = z__[j4 + 1];
        local_dmin = d__;
        local_emin = 0.;
    } else if (safmin * z__[j4 + 1] < z__[j4 - 2] && safmin * z__[j4 - 2] < z__[j4 + 1]) {
        temp = z__[j4 + 1] / z__[j4 - 2];
        z__[j4] = z__[j4 - 1] * temp;
        d__ *= temp;
    } else {
        z__[j4] = z__[j4 + 1] * (z__[j4 - 1] / z__[j4 - 2]);
        d__ = z__[j4 + 1] * (d__ / z__[j4 - 2]);
    }
    local_dmin = (local_dmin <= d__) ? local_dmin : d__;
    local_emin = (local_emin <= z__[j4]) ? local_emin : z__[j4];
}
*dmin__ = local_dmin;
emin = local_emin;
}
