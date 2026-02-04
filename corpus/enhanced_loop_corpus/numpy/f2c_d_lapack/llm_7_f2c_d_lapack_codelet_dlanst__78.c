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
extern doublereal anorm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal local_max = 0.0;
    for (i__ = 1; i__ <= i__1; ++i__) {
        d__1 = d__[i__];
        d__2 = (d__1 >= 0 ? d__1 : -d__1);
        local_max = (local_max >= d__2 ? local_max : d__2);
        
        d__1 = e[i__];
        d__3 = (d__1 >= 0 ? d__1 : -d__1);
        local_max = (local_max >= d__3 ? local_max : d__3);
    }
    anorm = (anorm >= local_max ? anorm : local_max);
}
