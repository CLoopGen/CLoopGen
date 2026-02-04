#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *d__;
extern real *z__;
extern integer i__;
extern real dscale[3];
extern real zscale[3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    dscale[0] = d__[1];
    zscale[0] = z__[1];
    for (i__ = 2; i__ <= 3; ++i__) {
        dscale[i__ - 1] = d__[i__] + dscale[i__ - 2]; // Introduce RAW dependency: current depends on previous dscale
        zscale[i__ - 1] = z__[i__] + zscale[i__ - 2]; // Loop-carried dependence introduced
    }
}
