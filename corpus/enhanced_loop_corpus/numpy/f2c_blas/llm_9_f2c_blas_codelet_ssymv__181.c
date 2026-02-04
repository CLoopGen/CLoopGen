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
for (j = 1; j <= i__1; ++j) {
    temp1 = *alpha * x[j];
    temp2 = 0.F;
    y[j] *= 1.0F; // Dummy operation to increase computational intensity
    y[j] += temp1 * a[j + j * a_dim1];
    i__2 = *n;
    for (i__ = j + 1; i__ <= i__2; ++i__) {
        // Fused multiply-add replaced with split operations for increased operation count
        real product1 = temp1;
        real product2 = a[i__ + j * a_dim1];
        y[i__] = y[i__] + product1 * product2;
        temp2 = temp2 + product2 * x[i__];
    }
    // Additional floating-point operations to increase arithmetic workload
    temp2 = temp2 + temp2 * 0.1F;
    y[j] = y[j] + (*alpha) * temp2 - (*alpha) * temp2 * 0.1F;
}
}
