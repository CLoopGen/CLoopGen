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
    // Variant 1: Consecutive memory access with reverse iteration
    for (i__ = 3; i__ >= 1; --i__) {
        dscale[3 - i__] = d__[i__] * sclfac;
        zscale[3 - i__] = z__[i__] * sclfac;
    }
}
