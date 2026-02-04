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
    y[j] = a[j + j * a_dim1] > 0.0F ? y[j] + temp1 * a[j + j * a_dim1] : y[j];
    i__2 = *n;
    for (i__ = j + 1; i__ <= i__2; ++i__) {
        real coeff = a[i__ + j * a_dim1];
        if (coeff > 1e-6F) {
            y[i__] += temp1 * coeff;
            temp2 += coeff * x[i__];
        } else if (coeff < -1e-6F) {
            y[i__ + 1] += temp1 * coeff;
            temp2 += coeff * x[i__];
        }
    }
    y[j] += *alpha * temp2;
}
}
