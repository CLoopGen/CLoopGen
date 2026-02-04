#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *dx;
extern doublereal *dy;
extern integer i__1;
extern integer i__;
extern integer mp1;
extern doublereal dtemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal temp_dx, temp_dy;
    for (i__ = mp1; i__ <= i__1; i__ += 3) {
        temp_dx = dx[i__];
        temp_dy = dy[i__];
        dx[i__] = temp_dy;
        dy[i__] = temp_dx;

        temp_dx = dx[i__ + 1];
        temp_dy = dy[i__ + 1];
        dx[i__ + 1] = temp_dy;
        dy[i__ + 1] = temp_dx;

        temp_dx = dx[i__ + 2];
        temp_dy = dy[i__ + 2];
        dx[i__ + 2] = temp_dy;
        dy[i__ + 2] = temp_dx;
    }
}
