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
for (i__ = mp1; i__ <= i__1; i__ += 2) {
    stemp = sx[i__];
    sx[i__] = sy[i__];
    sy[i__] = stemp;
    if (i__ + 1 <= i__1) {
        stemp = sx[i__ + 1];
        sx[i__ + 1] = sy[i__ + 1];
        sy[i__ + 1] = stemp;
    }
}
}
