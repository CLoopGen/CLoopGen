#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern doublereal *z__;
extern integer i__;
extern doublereal dscale[3];
extern doublereal sclfac;
extern doublereal zscale[3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= 3; ++i__) {
    doublereal temp_d = d__[i__] * sclfac;
    doublereal temp_z = z__[i__] * sclfac;
    dscale[i__ - 1] = temp_d;
    zscale[i__ - 1] = temp_z;
    // Additional computational load without changing trip count
    dscale[i__ - 1] *= (temp_d > 0.0) ? 1.0 : -1.0;
    zscale[i__ - 1] += (temp_z < 0.0) ? temp_z * 0.1 : 0.0;
}
}
