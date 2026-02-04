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
    for (int stride = 0; stride < 3; ++stride) {
        for (i__ = mp1 + stride; i__ <= i__1; i__ += 3) {
            if ((i__ - mp1) % 3 == stride) {
                dtemp = dx[i__];
                dx[i__] = dy[i__];
                dy[i__] = dtemp;
            }
        }
    }
}
