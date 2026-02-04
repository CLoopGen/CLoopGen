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
        doublereal temp_sum1 = dy[i__] + *da * dx[i__];
        doublereal temp_sum2 = dy[i__ + 1] + *da * dx[i__ + 1];
        dy[i__] = temp_sum1;
        dy[i__ + 1] = temp_sum2;
        if (i__ + 2 <= i__1) {
            dy[i__ + 2] = dy[i__ + 2] + *da * dx[i__ + 2];
        }
        if (i__ + 3 <= i__1) {
            dy[i__ + 3] = dy[i__ + 3] + *da * dx[i__ + 3];
        }
    }
}
