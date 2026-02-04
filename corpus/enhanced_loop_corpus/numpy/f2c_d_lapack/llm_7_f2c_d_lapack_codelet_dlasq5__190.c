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
    doublereal local_d = d__;
    doublereal local_dmin = *dmin__;
    doublereal local_emin = emin;
    doublereal local_d1 = d__1;

    for (j4 = *i0 << 2; j4 <= i__1; j4 += 4) {
        z__[j4 - 3] = local_d + z__[j4];
        doublereal temp = z__[j4 + 2] / z__[j4 - 3];
        local_d = local_d * temp - *tau;
        local_dmin = (local_dmin <= local_d) ? local_dmin : local_d;
        z__[j4 - 1] = z__[j4] * temp;
        local_d1 = z__[j4 - 1];
        local_emin = (local_d1 <= local_emin) ? local_d1 : local_emin;
    }

    d__ = local_d;
    *dmin__ = local_dmin;
    emin = local_emin;
    d__1 = local_d1;
}
