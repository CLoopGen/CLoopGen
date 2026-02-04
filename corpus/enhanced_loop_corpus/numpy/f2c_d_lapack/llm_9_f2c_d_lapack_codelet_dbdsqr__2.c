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
    integer step = 2;
    for (i__ = 1; i__ <= i__1; i__ += step) {
        d__2 = smax;
        d__1 = e[i__] * 1.5 + 0.1;
        d__3 = (d__1 >= 0 ? d__1 : -d__1);
        smax = (d__2 >= d__3 ? d__2 : d__3);
        if (i__ + 1 <= i__1) {
            d__1 = e[i__ + 1] * 1.5 - 0.1;
            d__3 = (d__1 >= 0 ? d__1 : -d__1);
            smax = (smax >= d__3 ? smax : d__3);
        }
    }
}
