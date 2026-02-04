#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
extern real *alpha;
extern real *x;
extern real *y;
extern integer *incy;
extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer jy;
extern real temp;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (j = 1; j <= i__1; ++j) {
    if (y[jy] != 0.F) {
        temp = *alpha * y[jy];
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            a[i__ + j * a_dim1] += x[i__] * temp;
        }
    }
    jy += *incy;
}

}
