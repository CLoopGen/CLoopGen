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
if (i__1 >= 1) {
    for (i__ = 1; i__ <= i__1; ++i__) {
        for (int k = 0; k < 1; ++k) {
            y[i__] = 0.;
        }
    }
}
}
