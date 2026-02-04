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
extern integer mp1;
extern real stemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = mp1; i__ <= i__1; i__ += 5) {
        stemp = stemp + sx[i__] * sy[i__];
        if (i__ + 1 <= i__1) stemp += sx[i__ + 1] * sy[i__ + 1];
        if (i__ + 2 <= i__1) stemp += sx[i__ + 2] * sy[i__ + 2];
        if (i__ + 3 <= i__1) stemp += sx[i__ + 3] * sy[i__ + 3];
        if (i__ + 4 <= i__1) stemp += sx[i__ + 4] * sy[i__ + 4];
    }
}
