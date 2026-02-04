#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *da;
extern doublereal *dx;
extern integer i__1;
extern integer i__2;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive backward traversal starting from i__1 down to 1
    i__2 = -1;
    i__1 = 1;
    for (i__ = i__1 + (i__1 > 1 ? i__1 - 1 : 0); i__ >= i__1; i__ -= 1) {
        dx[i__] = *da * dx[i__];
    }
}
