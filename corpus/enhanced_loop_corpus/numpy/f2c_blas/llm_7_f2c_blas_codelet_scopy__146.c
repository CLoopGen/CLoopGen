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
    for (i__ = mp1; i__ <= i__1; i__ += 7) {
        sy[i__] = sx[i__];
        sy[i__] += sx[i__ + 1]; // Introduce WAW and RAW: sy[i__] depends on previous write and sx[i__+1]
        sy[i__ + 1] = sy[i__];  // WAR/WAW: use updated sy[i__] to affect sy[i__+1]
        sy[i__ + 2] = sx[i__ + 2];
        sy[i__ + 3] = sx[i__ + 3];
        sy[i__ + 4] = sx[i__ + 4];
        sy[i__ + 5] = sx[i__ + 5];
        sy[i__ + 6] = sx[i__ + 6];
    }
}
