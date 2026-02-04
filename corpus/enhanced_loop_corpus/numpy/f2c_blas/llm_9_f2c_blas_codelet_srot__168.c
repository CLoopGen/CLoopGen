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
for (i__ = 1; i__ <= i__1; i__ += 2) {
    if (i__ + 1 <= i__1) {
        stemp = *c__ * sx[i__] + *s * sy[i__];
        sy[i__] = *c__ * sy[i__] - *s * sx[i__];
        sx[i__] = stemp;

        stemp = *c__ * sx[i__+1] + *s * sy[i__+1];
        sy[i__+1] = *c__ * sy[i__+1] - *s * sx[i__+1];
        sx[i__+1] = stemp;
    } else {
        stemp = *c__ * sx[i__] + *s * sy[i__];
        sy[i__] = *c__ * sy[i__] - *s * sx[i__];
        sx[i__] = stemp;
    }
}
}
