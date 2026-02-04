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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = mp1; i__ <= i__1 - 6; i__ += 7) {
        real temp1 = sx[i__];
        real temp2 = sx[i__ + 1];
        real temp3 = sx[i__ + 2];
        real temp4 = sx[i__ + 3];
        real temp5 = sx[i__ + 4];
        real temp6 = sx[i__ + 5];
        real temp7 = sx[i__ + 6];

        sy[i__] = temp1;
        sy[i__ + 1] = temp2;
        sy[i__ + 2] = temp3;
        sy[i__ + 3] = temp4;
        sy[i__ + 4] = temp5;
        sy[i__ + 5] = temp6;
        sy[i__ + 6] = temp7;
    }
}
