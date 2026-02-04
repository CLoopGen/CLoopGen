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
    real local_norm = 0.0f;
    for (i__ = 1; i__ <= i__1; ++i__) {
        r__1 = d__[i__];
        r__2 = (doublereal)((r__1) >= 0 ? (r__1) : -(r__1));
        if (r__2 > local_norm) local_norm = r__2;

        r__1 = e[i__];
        r__2 = (doublereal)((r__1) >= 0 ? (r__1) : -(r__1));
        if (r__2 > local_norm) local_norm = r__2;
    }
    if (local_norm > anorm) {
        anorm = local_norm;
    }
}
