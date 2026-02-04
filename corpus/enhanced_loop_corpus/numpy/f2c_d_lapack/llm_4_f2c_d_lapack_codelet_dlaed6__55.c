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
    for (i__ = 1; i__ <= 3; ++i__) {
        if (d__[i__] >= 0.0) {
            dscale[i__ - 1] = d__[i__];
        } else {
            dscale[i__ - 1] = 0.0;
        }
        zscale[i__ - 1] = z__[i__];
    }
}
