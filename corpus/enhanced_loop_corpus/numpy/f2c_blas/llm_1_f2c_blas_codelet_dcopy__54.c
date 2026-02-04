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
if (mp1 <= i__1) {
    for (int k = 0; k < 7; ++k) {
        for (i__ = mp1 + k; i__ <= i__1; i__ += 7) {
            dy[i__] = dx[i__];
        }
    }
}
}
