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
extern real stemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1; ++i__) {
    for (integer k = 0; k < 1; ++k) {
        stemp += sx[i__] * sy[i__];
    }
}
}
