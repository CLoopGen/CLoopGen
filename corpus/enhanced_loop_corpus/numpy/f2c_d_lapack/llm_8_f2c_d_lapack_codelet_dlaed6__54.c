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
for (i__ = 1; i__ <= 6; ++i__) {
    if (i__ <= 3) {
        dscale[i__ - 1] = d__[i__] * sclfac + d__[i__] * sclfac * 0.1;
        zscale[i__ - 1] = z__[i__] * sclfac - z__[i__] * sclfac * 0.05;
    } else {
        integer j = i__ - 4;
        dscale[j] = (d__[j+1] * sclfac * 1.2) + (d__[j+1] * sclfac * 0.08);
        zscale[j] = (z__[j+1] * sclfac * 0.9) - (z__[j+1] * sclfac * 0.02);
    }
}
}
