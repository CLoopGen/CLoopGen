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
    real temp1, temp2, temp3;
    for (i__ = mp1; i__ <= i__1; i__ += 3) {
        temp1 = sx[i__];
        temp2 = sx[i__ + 1];
        temp3 = sx[i__ + 2];
        sx[i__] = sy[i__];
        sx[i__ + 1] = sy[i__ + 1];
        sx[i__ + 2] = sy[i__ + 2];
        sy[i__] = temp1;
        sy[i__ + 1] = temp2;
        sy[i__ + 2] = temp3;
    }
}
