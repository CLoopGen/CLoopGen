#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *da;
extern doublereal *dx;
extern integer i__2;
extern integer i__;
extern integer mp1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = mp1; i__ <= i__2; i__ += 5) {
    for (int j = 0; j < 5; ++j) {
        if (i__ + j <= i__2) {
            dx[i__ + j] = *da * dx[i__ + j];
        }
    }
}
}
