#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *da;
extern doublereal *dx;
extern integer i__2;
extern integer i__;
extern integer mp1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = mp1; i__ <= i__2; i__ += 5) {
        doublereal temp1 = *da * dx[i__];
        doublereal temp2 = *da * dx[i__ + 1];
        doublereal temp3 = *da * dx[i__ + 2];
        doublereal temp4 = *da * dx[i__ + 3];
        doublereal temp5 = *da * dx[i__ + 4];
        dx[i__] = temp1;
        dx[i__ + 1] = temp2;
        dx[i__ + 2] = temp3;
        dx[i__ + 3] = temp4;
        dx[i__ + 4] = temp5;
    }
}
