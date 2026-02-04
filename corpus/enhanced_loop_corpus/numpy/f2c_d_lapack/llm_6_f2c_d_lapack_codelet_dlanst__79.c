#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern doublereal *e;
extern integer i__1;
extern doublereal d__1;
extern doublereal d__2;
extern doublereal d__3;
extern doublereal d__4;
extern doublereal d__5;
extern integer i__;
extern doublereal anorm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal temp_anorm = anorm;
    for (i__ = 2; i__ <= i__1; ++i__) {
        d__4 = temp_anorm;
        d__5 = (d__1 = d__[i__], ((d__1) >= 0 ? (d__1) : -(d__1))) + 
               (d__2 = e[i__], ((d__2) >= 0 ? (d__2) : -(d__2))) + 
               (d__3 = e[i__ - 1], ((d__3) >= 0 ? (d__3) : -(d__3)));
        temp_anorm = ((d__4) >= (d__5) ? (d__4) : (d__5));
    }
    anorm = temp_anorm;
}
