#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *alpha;
extern real *x;
extern real *y;
extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern real temp1;
extern real temp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    temp1 = *alpha * y[j];
    temp2 = *alpha * x[j];
    i__2 = j;
    for (i__ = 1; i__ <= i__2; ++i__) {
        real xi = x[i__];
        real yi = y[i__];
        real aj = a[i__ + j * a_dim1];
        aj += xi * temp1 + yi * temp2;
        a[i__ + j * a_dim1] = aj;
    }
}
}
