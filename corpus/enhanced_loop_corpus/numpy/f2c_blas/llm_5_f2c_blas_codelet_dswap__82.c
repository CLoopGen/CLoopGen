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
    for (i__ = mp1; i__ <= i__1; i__ += 3) {
        if (dx[i__] >= dy[i__]) {
            dtemp = dx[i__];
            dx[i__] = dy[i__];
            dy[i__] = dtemp;
        }
        if (dx[i__ + 1] >= dy[i__ + 1]) {
            dtemp = dx[i__ + 1];
            dx[i__ + 1] = dy[i__ + 1];
            dy[i__ + 1] = dtemp;
        }
        if (dx[i__ + 2] >= dy[i__ + 2]) {
            dtemp = dx[i__ + 2];
            dx[i__ + 2] = dy[i__ + 2];
            dy[i__ + 2] = dtemp;
        }
    }
}
