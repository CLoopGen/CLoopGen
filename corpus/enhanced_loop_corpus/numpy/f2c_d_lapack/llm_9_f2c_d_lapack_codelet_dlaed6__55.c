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
extern doublereal zscale[3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 1; i__ <= 6; ++i__) {
        int idx = (i__ - 1) % 3;
        dscale[idx] = (d__[idx + 1] + d__[idx + 1]) * 0.5;
        zscale[idx] = (z__[idx + 1] + z__[idx + 1]) * 0.5;
    }
}
