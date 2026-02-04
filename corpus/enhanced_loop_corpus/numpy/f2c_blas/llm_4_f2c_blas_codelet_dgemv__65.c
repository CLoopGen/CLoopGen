#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *beta;
extern doublereal *y;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (i__1 <= 0) return;
    for (i__ = 1; i__ <= i__1; ++i__) {
        if (y[i__] == 0.0) continue;
        y[i__] = *beta * y[i__];
    }
}
