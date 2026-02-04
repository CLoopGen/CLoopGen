#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *tau;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal temp = 0.;
    for (i__ = 1; i__ <= i__1; ++i__) {
        temp += tau[i__];
        tau[i__] = 0.;
    }
    // Introduced a loop-carried dependency via 'temp' (accumulation pattern)
    // RAW dependency: each iteration reads 'temp' written in previous iteration
}
