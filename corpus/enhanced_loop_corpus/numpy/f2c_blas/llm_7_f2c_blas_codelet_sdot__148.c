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
    real local_stemp = 0.0;
    for (i__ = 1; i__ <= i__1; ++i__) {
        local_stemp += sx[i__] * sy[i__];
    }
    stemp += local_stemp;
}
