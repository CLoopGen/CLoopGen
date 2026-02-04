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
    doublereal temp1 = 0.0, temp2 = 0.0, temp3 = 0.0, temp4 = 0.0, temp5 = 0.0;
    for (i__ = mp1; i__ <= i__1 - 4; i__ += 5) {
        temp1 += dx[i__] * dy[i__];
        temp2 += dx[i__ + 1] * dy[i__ + 1];
        temp3 += dx[i__ + 2] * dy[i__ + 2];
        temp4 += dx[i__ + 3] * dy[i__ + 3];
        temp5 += dx[i__ + 4] * dy[i__ + 4];
    }
    dtemp = dtemp + temp1 + temp2 + temp3 + temp4 + temp5;
}
