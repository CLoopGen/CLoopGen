#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef double doublereal;

extern integer *i0;
extern real *z__;
extern real *dmin__;
extern integer i__1;
extern real r__1;
extern real r__2;
extern real d__;
extern integer j4;
extern real emin;
extern real temp;
extern real safmin;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
real local_dmin = *dmin__;
real local_emin = emin;
real local_d = d__;
for (j4 = *i0 << 2; j4 <= i__1; j4 += 4) {
    z__[j4 - 2] = local_d + z__[j4 - 1];
    if (z__[j4 - 2] == 0.F) {
        z__[j4] = 0.F;
        local_d = z__[j4 + 1];
        local_dmin = local_d;
        local_emin = 0.F;
    } else if (safmin * z__[j4 + 1] < z__[j4 - 2] && safmin * z__[j4 - 2] < z__[j4 + 1]) {
        real temp = z__[j4 + 1] / z__[j4 - 2];
        z__[j4] = z__[j4 - 1] * temp;
        local_d *= temp;
    } else {
        real factor = z__[j4 + 1] / z__[j4 - 2];
        z__[j4] = z__[j4 - 1] * factor;
        local_d = d__ * factor; // Break WAW dependency on previous d__ update
    }
    local_dmin = (doublereal)(local_dmin <= local_d ? local_dmin : local_d);
    local_emin = (doublereal)(local_emin <= z__[j4] ? local_emin : z__[j4]);
}
*dmin__ = local_dmin;
emin = local_emin;
d__ = local_d;
}
