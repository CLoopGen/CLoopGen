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
for (integer stride = 0; stride < 4; stride++) {
    for (i__ = mp1 + stride; i__ <= i__1; i__ += 4) {
        if (i__ <= i__1) {
            sy[i__] += *sa * sx[i__];
        }
    }
}
}
