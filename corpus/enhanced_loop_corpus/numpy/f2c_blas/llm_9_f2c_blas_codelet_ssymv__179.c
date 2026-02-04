#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *alpha;
extern real *a;
extern real *x;
extern real *y;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern real temp1;
extern real temp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; j += 2) {
    integer j1 = j;
    integer j2 = j + 1;
    if (j1 <= i__1) {
        temp1 = *alpha * x[j1];
        temp2 = 0.F;
        i__2 = j1 - 1;
        for (i__ = 1; i__ <= i__2; ++i__) {
            y[i__] += temp1 * a[i__ + j1 * a_dim1];
            temp2 += a[i__ + j1 * a_dim1] * x[i__];
        }
        y[j1] = y[j1] + temp1 * a[j1 + j1 * a_dim1] + *alpha * temp2;
    }
    if (j2 <= i__1) {
        temp1 = *alpha * x[j2];
        temp2 = 0.F;
        i__2 = j2 - 1;
        for (i__ = 1; i__ <= i__2; ++i__) {
            y[i__] += temp1 * a[i__ + j2 * a_dim1];
            temp2 += a[i__ + j2 * a_dim1] * x[i__];
        }
        y[j2] = y[j2] + temp1 * a[j2 + j2 * a_dim1] + *alpha * temp2;
    }
}
}
