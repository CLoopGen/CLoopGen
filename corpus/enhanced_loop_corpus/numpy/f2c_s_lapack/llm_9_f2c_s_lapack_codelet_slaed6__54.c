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
extern real sclfac;
extern real zscale[3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= 6; ++i__) {
    int idx = (i__ - 1) % 3;
    int src = ((i__ - 1) / 3) + 1;
    if (i__ <= 3) {
        dscale[idx] = d__[src] * sclfac;
    } else {
        zscale[idx] = z__[src] * sclfac;
    }
}
}
