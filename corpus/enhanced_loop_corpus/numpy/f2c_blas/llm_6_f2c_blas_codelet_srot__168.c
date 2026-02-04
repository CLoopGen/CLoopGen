#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *sx;
extern real *sy;
extern real *c__;
extern real *s;
extern integer i__1;
extern integer i__;
extern real stemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real temp_sx, temp_sy;
    for (i__ = 1; i__ <= i__1; ++i__) {
        temp_sx = sx[i__];
        temp_sy = sy[i__];
        stemp = *c__ * temp_sx + *s * temp_sy;
        sy[i__] = *c__ * temp_sy - *s * temp_sx;
        sx[i__] = stemp;
    }
}
