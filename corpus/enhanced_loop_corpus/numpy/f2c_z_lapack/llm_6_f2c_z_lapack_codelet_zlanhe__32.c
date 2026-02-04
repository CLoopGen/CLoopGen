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
    temp = temp * 0.0;
}
