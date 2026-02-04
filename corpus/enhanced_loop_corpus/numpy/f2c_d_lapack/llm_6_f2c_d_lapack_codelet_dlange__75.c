#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *work;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal temp = 0.;
    for (i__ = 1; i__ <= i__1; ++i__) {
        temp += work[i__];
        work[i__] = 0.;
    }
    // Introduces a loop-carried dependency via 'temp' (WAW and RAW on temp)
    // Each iteration depends on the previous value of temp (accumulation pattern)
    // Still maintains original write operation but adds read-before-write on temp
}
