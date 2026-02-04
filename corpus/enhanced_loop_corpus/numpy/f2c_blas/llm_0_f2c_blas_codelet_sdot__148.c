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
for (integer j = 0; j < 1; ++j) {
    for (i__ = 1; i__ <= i__1; ++i__) {
        stemp += sx[i__] * sy[i__];
    }
}
}
