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
    for (integer k = 1; k <= j - 1; ++k) {
        i__ = k;
        work[j] += (r__1 = t[i__ + j * t_dim1] , (doublereal)((r__1) >= 0 ? (r__1) : -(r__1)));
    }
}
}
