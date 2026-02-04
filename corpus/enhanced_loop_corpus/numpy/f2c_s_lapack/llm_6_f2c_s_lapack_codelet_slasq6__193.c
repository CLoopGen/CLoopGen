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
for (j4 = *i0 << 2; j4 <= i__1; j4 += 4) {
    real temp_z_j4_minus_2 = d__ + z__[j4 - 1];
    z__[j4 - 2] = temp_z_j4_minus_2;
    if (temp_z_j4_minus_2 == 0.F) {
        z__[j4] = 0.F;
        d__ = z__[j4 + 1];
        *dmin__ = d__;
        emin = 0.F;
    } else if (safmin * z__[j4 + 1] < temp_z_j4_minus_2 && safmin * temp_z_j4_minus_2 < z__[j4 + 1]) {
        real temp_ratio = z__[j4 + 1] / temp_z_j4_minus_2;
        z__[j4] = z__[j4 - 1] * temp_ratio;
        d__ *= temp_ratio;
    } else {
        real inv_denom = 1.0F / temp_z_j4_minus_2;
        z__[j4] = z__[j4 + 1] * (z__[j4 - 1] * inv_denom);
        d__ = z__[j4 + 1] * (d__ * inv_denom);
    }
    real current_dmin = (*dmin__);
    *dmin__ = (doublereal)(current_dmin <= d__ ? current_dmin : d__);
    real current_emin = emin;
    emin = (doublereal)(current_emin <= z__[j4] ? current_emin : z__[j4]);
}
}
