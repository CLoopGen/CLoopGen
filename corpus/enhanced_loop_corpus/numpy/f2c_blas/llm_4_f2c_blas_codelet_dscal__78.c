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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (i__2 <= 0) return;
    for (i__ = 1; i__ <= i__2; ++i__) {
        dx[i__] = *da * dx[i__];
    }
}
