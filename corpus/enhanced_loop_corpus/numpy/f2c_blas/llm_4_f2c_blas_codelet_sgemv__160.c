#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
extern real *alpha;
extern real *a;
extern real *x;
extern integer *incx;
extern real *y;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer jx;
extern real temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    temp = *alpha * x[jx];
    i__2 = *m;
    for (i__ = 1; i__ <= i__2; ++i__) {
        y[i__] += temp * a[i__ + j * a_dim1];
    }
    jx += *incx;
}
}
