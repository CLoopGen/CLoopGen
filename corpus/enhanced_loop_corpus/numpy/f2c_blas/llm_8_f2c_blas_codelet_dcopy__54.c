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
    for (i__ = mp1; i__ <= i__1; i__ += 14) {
        dy[i__] = dx[i__];
        dy[i__ + 1] = dx[i__ + 1];
        dy[i__ + 2] = dx[i__ + 2];
        dy[i__ + 3] = dx[i__ + 3];
        dy[i__ + 4] = dx[i__ + 4];
        dy[i__ + 5] = dx[i__ + 5];
        dy[i__ + 6] = dx[i__ + 6];
        if (i__ + 7 <= i__1) dy[i__ + 7] = dx[i__ + 7];
        if (i__ + 8 <= i__1) dy[i__ + 8] = dx[i__ + 8];
        if (i__ + 9 <= i__1) dy[i__ + 9] = dx[i__ + 9];
        if (i__ + 10 <= i__1) dy[i__ + 10] = dx[i__ + 10];
        if (i__ + 11 <= i__1) dy[i__ + 11] = dx[i__ + 11];
        if (i__ + 12 <= i__1) dy[i__ + 12] = dx[i__ + 12];
        if (i__ + 13 <= i__1) dy[i__ + 13] = dx[i__ + 13];
    }
}
