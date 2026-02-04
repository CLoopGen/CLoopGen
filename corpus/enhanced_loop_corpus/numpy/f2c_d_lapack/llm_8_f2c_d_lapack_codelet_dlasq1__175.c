#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern doublereal *e;
extern integer i__1;
extern doublereal d__1;
extern doublereal d__2;
extern doublereal d__3;
extern integer i__;
extern doublereal sigmx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Introduce artificial loop-carried dependency via cumulative operation to increase RAW dependence
    doublereal running_max = sigmx;
    for (i__ = 1; i__ <= i__1; ++i__) {
        d__[i__] = (d__1 = d__[i__], ((d__1) >= 0 ? (d__1) : -(d__1)));
        d__3 = (d__1 = e[i__], ((d__1) >= 0 ? (d__1) : -(d__1)));
        // Make current iteration's sigmx value depend on previous iteration's result (added RAW)
        if (i__ > 1) {
            running_max = ((running_max) >= (d__3) ? (running_max) : (d__3));
        } else {
            running_max = d__3; // Initialize with first element
        }
    }
    sigmx = running_max;
}
