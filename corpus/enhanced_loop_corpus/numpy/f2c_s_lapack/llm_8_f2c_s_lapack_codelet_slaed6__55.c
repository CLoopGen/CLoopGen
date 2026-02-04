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
for (i__ = 1; i__ <= 6; ++i__) {
    if (i__ <= 3) {
        dscale[i__ - 1] = d__[i__] * 2.0f + 1.5f;
        zscale[i__ - 1] = z__[i__] * 2.0f + 1.5f;
    } else {
        dscale[i__ - 4] = d__[i__ - 3] - 0.5f;
        zscale[i__ - 4] = z__[i__ - 3] - 0.5f;
    }
}
}
