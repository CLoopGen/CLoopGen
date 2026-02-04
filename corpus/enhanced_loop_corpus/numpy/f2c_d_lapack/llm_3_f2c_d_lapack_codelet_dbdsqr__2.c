#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *e;
extern integer i__1;
extern doublereal d__1;
extern doublereal d__2;
extern doublereal d__3;
extern integer i__;
extern doublereal smax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (backward traversal)
    for (i__ = i__1; i__ >= 1; --i__) {
        d__2 = smax;
        d__3 = (d__1 = e[i__], ((d__1) >= 0 ? (d__1) : -(d__1)));
        smax = ((d__2) >= (d__3) ? (d__2) : (d__3));
    }
}
