#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *da;
extern doublereal *dx;
extern doublereal *dy;
extern integer i__1;
extern integer i__;
extern integer mp1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = mp1; i__ <= i__1; i__ += 4) {
        double temp_da = *da;
        if (dx[i__] != 0.0) dy[i__] += temp_da * dx[i__];
        if (i__ + 1 <= i__1 && dx[i__ + 1] != 0.0) dy[i__ + 1] += temp_da * dx[i__ + 1];
        if (i__ + 2 <= i__1 && dx[i__ + 2] != 0.0) dy[i__ + 2] += temp_da * dx[i__ + 2];
        if (i__ + 3 <= i__1 && dx[i__ + 3] != 0.0) dy[i__ + 3] += temp_da * dx[i__ + 3];
    }
}
