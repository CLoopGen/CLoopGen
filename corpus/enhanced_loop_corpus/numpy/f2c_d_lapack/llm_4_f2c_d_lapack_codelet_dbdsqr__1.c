#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern integer i__1;
extern doublereal d__1;
extern doublereal d__2;
extern doublereal d__3;
extern integer i__;
extern doublereal smax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 1; i__ <= i__1; ++i__) {
        doublereal abs_val = d__[i__];
        if (abs_val < 0) abs_val = -abs_val;
        if (abs_val > smax) {
            smax = abs_val;
        }
    }
}
