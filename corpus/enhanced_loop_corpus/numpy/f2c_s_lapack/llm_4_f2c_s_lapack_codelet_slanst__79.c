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
extern real r__4;
extern real r__5;
extern integer i__;
extern real anorm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 2; i__ <= i__1; ++i__) {
    real abs_d = (r__1 = d__[i__], (r__1) >= 0 ? r__1 : -r__1);
    real abs_e_i = (r__2 = e[i__], (r__2) >= 0 ? r__2 : -r__2);
    real abs_e_im1 = (r__3 = e[i__ - 1], (r__3) >= 0 ? r__3 : -r__3);
    real candidate = abs_d + abs_e_i + abs_e_im1;
    if (candidate > anorm) {
        anorm = candidate;
    }
}
}
