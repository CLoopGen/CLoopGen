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
    doublereal acc_d = 0.0, acc_z = 0.0;
    for (i__ = 1; i__ <= 3; ++i__) {
        acc_d += d__[i__] * sclfac;
        acc_z += z__[i__] * sclfac;
        dscale[i__ - 1] = acc_d;
        zscale[i__ - 1] = acc_z;
    }
}
