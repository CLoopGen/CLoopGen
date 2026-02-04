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
    for (i__ = mp1; i__ <= i__1; i__ += 3) {
        dy[i__] = dx[i__] * 1.5 + 0.1;
        if (i__ + 1 <= i__1) {
            dy[i__ + 1] = dx[i__ + 1] * 1.5 + 0.1;
        }
        if (i__ + 2 <= i__1) {
            dy[i__ + 2] = dx[i__ + 2] * 1.5 + 0.1;
        }
    }
}
