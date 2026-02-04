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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real accum = 0.0f;
    for (i__ = 1; i__ <= i__1; ++i__) {
        accum += sx[i__] * sy[i__];
        sy[i__] += *sa * sx[i__];
    }
    // Introduce a dummy use of accum to prevent elimination
    if (accum < 0) {
        sy[1] = accum;
    }
}
