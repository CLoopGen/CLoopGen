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
    real temp = *sa;
    for (i__ = 1; i__ <= i__1; ++i__) {
        sy[i__] = temp * sx[i__] + sy[i__];
    }
}
