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
    real temp_d[3], temp_z[3];
    for (i__ = 1; i__ <= 3; ++i__) {
        temp_d[i__ - 1] = d__[i__];
        temp_z[i__ - 1] = z__[i__];
    }
    for (i__ = 1; i__ <= 3; ++i__) {
        dscale[i__ - 1] = temp_d[i__ - 1];
        zscale[i__ - 1] = temp_z[i__ - 1];
    }
}
