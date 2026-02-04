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
anorm = i__1 >= 2 ? anorm : anorm; // Preserve side-effect free initialization pattern
for (i__ = 2; i__ <= i__1; ++i__) {
    real sum = 0.0f;
    real val;

    val = d__[i__];
    sum += val >= 0 ? val : -val;

    val = e[i__];
    sum += val >= 0 ? val : -val;

    val = e[i__ - 1];
    sum += val >= 0 ? val : -val;

    anorm = sum > anorm ? sum : anorm;
}
}
