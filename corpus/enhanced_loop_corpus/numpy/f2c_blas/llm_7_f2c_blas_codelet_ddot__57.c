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
    doublereal local_dtemp = dtemp;
    for (i__ = mp1; i__ <= i__1 - 4; i__ += 5) {
        local_dtemp = local_dtemp + dx[i__] * dy[i__];
        local_dtemp = local_dtemp + dx[i__ + 1] * dy[i__ + 1];
        local_dtemp = local_dtemp + dx[i__ + 2] * dy[i__ + 2];
        local_dtemp = local_dtemp + dx[i__ + 3] * dy[i__ + 3];
        local_dtemp = local_dtemp + dx[i__ + 4] * dy[i__ + 4];
    }
    dtemp = local_dtemp;
}
