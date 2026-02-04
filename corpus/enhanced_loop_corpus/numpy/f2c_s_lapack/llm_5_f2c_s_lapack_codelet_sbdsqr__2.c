#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef double doublereal;

extern real *e;
extern integer i__1;
extern real r__1;
extern real r__2;
extern real r__3;
extern integer i__;
extern real smax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
smax = (r__1 = e[1], (doublereal)((r__1) >= 0 ? (r__1) : -(r__1)));
for (i__ = 2; i__ <= i__1; ++i__) {
    real abs_e = e[i__] < 0.0f ? -e[i__] : e[i__];
    if (abs_e <= smax) continue;
    smax = abs_e;
}
}
