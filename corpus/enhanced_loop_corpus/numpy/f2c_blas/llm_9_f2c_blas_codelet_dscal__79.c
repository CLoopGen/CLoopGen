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
for (i__ = mp1; i__ <= i__2; i__ += 10) {
    dx[i__] = *da * dx[i__];
    dx[i__ + 1] = *da * dx[i__ + 1];
    dx[i__ + 2] = *da * dx[i__ + 2];
    dx[i__ + 3] = *da * dx[i__ + 3];
    dx[i__ + 4] = *da * dx[i__ + 4];
    dx[i__ + 5] = *da * dx[i__ + 5];
    dx[i__ + 6] = *da * dx[i__ + 6];
    dx[i__ + 7] = *da * dx[i__ + 7];
    dx[i__ + 8] = *da * dx[i__ + 8];
    dx[i__ + 9] = *da * dx[i__ + 9];
}
}
