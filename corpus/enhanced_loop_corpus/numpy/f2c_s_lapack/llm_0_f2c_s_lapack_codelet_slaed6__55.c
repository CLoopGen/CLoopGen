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
for (i__ = 1; i__ <= 3; ++i__) {
    for (int j = 0; j < 1; ++j) {
        dscale[i__ - 1] = d__[i__];
        zscale[i__ - 1] = z__[i__];
    }
}
}
