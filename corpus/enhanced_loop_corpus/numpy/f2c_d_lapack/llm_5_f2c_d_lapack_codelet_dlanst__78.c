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
for (i__ = 1; i__ <= i__1; ++i__) {
    doublereal temp_d = d__[i__];
    doublereal temp_e = e[i__];
    temp_d = temp_d < 0 ? -temp_d : temp_d;
    temp_e = temp_e < 0 ? -temp_e : temp_e;
    anorm = temp_d > anorm ? temp_d : anorm;
    anorm = temp_e > anorm ? temp_e : anorm;
}
}
