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
for (i__ = mp1; i__ <= i__1; i__++) {
    stemp = sx[i__] + sx[i__] * 0.5f;
    sx[i__] = sy[i__] - stemp * 0.1f;
    sy[i__] = stemp + sy[i__] * 0.2f;
    if (i__ + 1 <= i__1) {
        stemp = sx[i__ + 1] + sx[i__ + 1] * 0.5f;
        sx[i__ + 1] = sy[i__ + 1] - stemp * 0.1f;
        sy[i__ + 1] = stemp + sy[i__ + 1] * 0.2f;
        i__ += 1;
    }
}
}
