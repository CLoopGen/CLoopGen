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
    for (i__ = mp1; i__ <= i__1; i__ += 2) {
        dtemp = dtemp + dx[i__] * dy[i__];
        if (i__ + 1 <= i__1) {
            dtemp = dtemp + dx[i__ + 1] * dy[i__ + 1];
        }
    }
}
