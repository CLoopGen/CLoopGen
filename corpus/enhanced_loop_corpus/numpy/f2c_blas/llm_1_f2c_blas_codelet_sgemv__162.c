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
extern real *y;
extern integer *incy;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer jy;
extern real temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (i__1 <= 0 || *m <= 0) return;
    temp = 0.F;
    for (j = 1; j <= i__1; ++j) {
        i__2 = *m;
        i__ = 1;
        do {
            temp += a[i__ + j * a_dim1] * x[i__];
            ++i__;
        } while (i__ <= i__2);
        y[jy] += *alpha * temp;
        temp = 0.F;
        jy += *incy;
    }
}
