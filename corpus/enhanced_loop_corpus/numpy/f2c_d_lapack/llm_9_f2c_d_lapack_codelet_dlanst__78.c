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
integer stride = 2;
for (i__ = 1; i__ <= i__1; i__ += stride) {
    d__2 = anorm;
    d__1 = d__[i__];
    d__3 = (d__1 >= 0 ? d__1 : -d__1);
    anorm = (d__2 >= d__3 ? d__2 : d__3);
    if (i__ + 1 <= i__1) {
        d__1 = d__[i__ + 1];
        d__3 = (d__1 >= 0 ? d__1 : -d__1);
        anorm = (anorm >= d__3 ? anorm : d__3);
    }
    d__1 = e[i__];
    d__3 = (d__1 >= 0 ? d__1 : -d__1);
    anorm = (anorm >= d__3 ? anorm : d__3);
    if (i__ + 1 <= i__1) {
        d__1 = e[i__ + 1];
        d__3 = (d__1 >= 0 ? d__1 : -d__1);
        anorm = (anorm >= d__3 ? anorm : d__3);
    }
}
}
