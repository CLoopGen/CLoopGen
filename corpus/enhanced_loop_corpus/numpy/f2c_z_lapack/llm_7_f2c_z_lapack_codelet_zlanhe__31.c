#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *work;
extern integer i__1;
extern doublereal d__1;
extern doublereal d__2;
extern integer i__;
extern doublereal value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal local_max = work[1];
    for (i__ = 1; i__ <= i__1; ++i__) {
        d__1 = local_max;
        d__2 = work[i__];
        local_max = ((d__1) >= (d__2) ? (d__1) : (d__2));
    }
    d__1 = value;
    d__2 = local_max;
    value = ((d__1) >= (d__2) ? (d__1) : (d__2));
}
