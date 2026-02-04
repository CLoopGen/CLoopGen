#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *sa;
extern real *sx;
extern real *sy;
extern integer i__1;
extern integer i__;
extern integer mp1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = mp1; i__ <= i__1; i__ += 4) {
    if (sx[i__] != 0.0f) {
        sy[i__] += *sa * sx[i__];
    }
    if (sx[i__ + 1] != 0.0f) {
        sy[i__ + 1] += *sa * sx[i__ + 1];
    }
    if (sx[i__ + 2] != 0.0f) {
        sy[i__ + 2] += *sa * sx[i__ + 2];
    }
    if (sx[i__ + 3] != 0.0f) {
        sy[i__ + 3] += *sa * sx[i__ + 3];
    }
}
}
