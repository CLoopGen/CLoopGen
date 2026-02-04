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
    doublereal temp = *beta;
    for (i__ = 1; i__ <= i__1; ++i__) {
        doublereal local_y = y[i__];
        y[i__] = temp * local_y;
    }
}
