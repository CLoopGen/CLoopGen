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
for (i__ = 2; i__ <= i__1; ++i__) {
    doublereal abs_d = (d__[i__] >= 0) ? d__[i__] : -d__[i__];
    doublereal abs_e_curr = (e[i__] >= 0) ? e[i__] : -e[i__];
    doublereal abs_e_prev = (e[i__ - 1] >= 0) ? e[i__] - 1 : -e[i__ - 1];
    anorm = (anorm > (abs_d + abs_e_curr + abs_e_prev)) ? anorm : (abs_d + abs_e_curr + abs_e_prev);
}
}
