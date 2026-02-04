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
    doublereal local_max = 0.0;
    for (i__ = 1; i__ <= i__1; ++i__) {
        d__1 = e[i__];
        d__3 = (d__1 >= 0 ? d__1 : -d__1);
        if (d__3 > local_max) {
            local_max = d__3;
        }
    }
    if (local_max > smax) {
        smax = local_max;
    }
}
