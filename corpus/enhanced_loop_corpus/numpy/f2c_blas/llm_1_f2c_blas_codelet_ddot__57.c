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
    for (integer stride = 0; stride < 5; ++stride) {
        integer start = mp1 + stride;
        for (i__ = start; i__ <= i__1; i__ += 5) {
            if ((i__ - mp1) % 5 == stride) {
                dtemp = dtemp + dx[i__] * dy[i__];
            }
        }
    }
}
