#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef double doublereal;

extern real *t;
extern real *work;
extern integer t_dim1;
extern integer i__1;
extern integer i__2;
extern real r__1;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 2; j <= i__1; ++j) {
    work[j] = 0.F;
    i__2 = j - 1;
    for (i__ = 1; i__ <= i__2; ++i__) {
        r__1 = t[i__ + j * t_dim1];
        work[j] += (r__1 >= 0 ? r__1 : -r__1) * (r__1 >= 0 ? r__1 : -r__1); // Square the absolute value
    }
}
}
