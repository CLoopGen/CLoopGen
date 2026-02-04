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
extern doublereal d__4;
extern doublereal d__5;
extern integer i__;
extern doublereal anorm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
integer stride = 2;
for (i__ = 2; i__ <= i__1; i__ += stride) {
    doublereal sum1 = (d__[i__] >= 0 ? d__[i__] : -d__[i__]) + 
                      (e[i__] >= 0 ? e[i__] : -e[i__]) + 
                      (e[i__ - 1] >= 0 ? e[i__ - 1] : -e[i__ - 1]);
    if (i__ + 1 <= i__1) {
        doublereal sum2 = (d__[i__ + 1] >= 0 ? d__[i__ + 1] : -d__[i__ + 1]) + 
                          (e[i__ + 1] >= 0 ? e[i__ + 1] : -e[i__ + 1]) + 
                          (e[i__] >= 0 ? e[i__] : -e[i__]);
        anorm = (anorm > sum1) ? anorm : sum1;
        anorm = (anorm > sum2) ? anorm : sum2;
    } else {
        anorm = (anorm > sum1) ? anorm : sum1;
    }
}
}
