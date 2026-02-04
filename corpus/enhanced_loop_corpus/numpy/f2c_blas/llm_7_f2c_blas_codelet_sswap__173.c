#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *sx;
extern real *sy;
extern integer i__1;
extern integer i__;
extern real stemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real local_sx, local_sy;
    for (i__ = 1; i__ <= i__1; ++i__) {
        local_sx = sx[i__];
        local_sy = sy[i__];
        sx[i__] = local_sy;
        sy[i__] = local_sx;
    }
}
