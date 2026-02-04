#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *scale;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 1; i__ <= i__1; ++i__) {
        scale[i__] = 1.;
        if (i__ > 1) {
            scale[i__] += scale[i__ - 1] - 1.; // introduces RAW and loop-carried dependency: each iteration depends on previous scale value
        }
    }
}
