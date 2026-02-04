#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
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
    temp1 = *alpha * x[j];
    temp2 = 0.F;
    y[j] += temp1 * a[j + j * a_dim1];
    if (j + 1 <= i__1) {
        real temp1_next = *alpha * x[j + 1];
        real temp2_next = 0.F;
        y[j + 1] += temp1_next * a[(j + 1) + (j + 1) * a_dim1];
        i__2 = *n;
        for (i__ = j + 2; i__ <= i__2; ++i__) {
            y[i__] += temp1 * a[i__ + j * a_dim1] + temp1_next * a[i__ + (j + 1) * a_dim1];
            temp2 += a[i__ + j * a_dim1] * x[i__];
            temp2_next += a[i__ + (j + 1) * a_dim1] * x[i__];
        }
        y[j] += *alpha * temp2;
        y[j + 1] += *alpha * temp2_next;
    } else {
        i__2 = *n;
        for (i__ = j + 1; i__ <= i__2; ++i__) {
            y[i__] += temp1 * a[i__ + j * a_dim1];
            temp2 += a[i__ + j * a_dim1] * x[i__];
        }
        y[j] += *alpha * temp2;
    }
}
}
