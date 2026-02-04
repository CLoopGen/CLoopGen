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
for (i__ = mp1; i__ <= i__1; i__ += 7) {
    for (int j = 0; j < 7; ++j) {
        if (i__ + j <= i__1) {
            dy[i__ + j] = dx[i__ + j];
        }
    }
}
}
