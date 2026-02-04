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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = mp1; i__ <= i__1; i__++) {
    if ((i__ - mp1) % 7 == 0 && i__ + 6 <= i__1) {
        dy[i__]     = dx[i__];
        dy[i__ + 1] = dx[i__ + 1];
        dy[i__ + 2] = dx[i__ + 2];
        dy[i__ + 3] = dx[i__ + 3];
        dy[i__ + 4] = dx[i__ + 4];
        dy[i__ + 5] = dx[i__ + 5];
        dy[i__ + 6] = dx[i__ + 6];
        i__ += 6;
    }
}
}
