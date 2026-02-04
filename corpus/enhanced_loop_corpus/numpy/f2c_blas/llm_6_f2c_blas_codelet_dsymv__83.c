#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *y;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal temp = 0.;
    for (i__ = 1; i__ <= i__1; ++i__) {
        temp = y[i__] + temp;  // Introduce RAW dependency: each iteration depends on previous temp value
        y[i__] = 0.;
    }
}
