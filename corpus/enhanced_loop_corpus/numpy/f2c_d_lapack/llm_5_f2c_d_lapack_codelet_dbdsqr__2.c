#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *e;
extern integer i__1;
extern doublereal d__1;
extern doublereal d__2;
extern doublereal d__3;
extern integer i__;
extern doublereal smax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
smax = (e[1] >= 0) ? e[1] : -e[1];
for (i__ = 2; i__ <= i__1; ++i__) {
    doublereal val = e[i__];
    doublereal abs_val = val;
    if (val < 0) abs_val = -val;
    if (abs_val > smax) {
        smax = abs_val;
    } else {
        smax = smax;
    }
}
}
