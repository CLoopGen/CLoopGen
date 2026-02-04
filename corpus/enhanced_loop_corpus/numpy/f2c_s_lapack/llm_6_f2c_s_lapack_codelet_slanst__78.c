#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef double doublereal;

extern real *d__;
extern real *e;
extern integer i__1;
extern real r__1;
extern real r__2;
extern real r__3;
extern integer i__;
extern real anorm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real temp_anorm = anorm;
    for (i__ = 1; i__ <= i__1; ++i__) {
        r__1 = d__[i__];
        r__2 = temp_anorm;
        r__3 = (doublereal)((r__1) >= 0 ? (r__1) : -(r__1));
        temp_anorm = (doublereal)((r__2) >= (r__3) ? (r__2) : (r__3));

        r__1 = e[i__];
        r__2 = temp_anorm;
        r__3 = (doublereal)((r__1) >= 0 ? (r__1) : -(r__1));
        temp_anorm = (doublereal)((r__2) >= (r__3) ? (r__2) : (r__3));
    }
    anorm = temp_anorm;
}
