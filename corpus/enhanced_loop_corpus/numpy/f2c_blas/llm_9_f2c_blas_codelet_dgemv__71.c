#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *m;
extern doublereal *alpha;
extern doublereal *a;
extern doublereal *x;
extern integer *incx;
extern doublereal *y;
extern integer *incy;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer ix;
extern integer jy;
extern integer kx;
extern doublereal temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with increased data reuse and modified loop bounds.
    // Outer loop runs every other index to reduce total iterations by ~half.
    // Inner loop accumulates two outputs per iteration using dual accumulation to maintain workload.

    integer step_j = 2;
    for (j = 1; j <= i__1; j += step_j) {
        temp = 0.;
        doublereal temp2 = 0.; // Second accumulator for j+1
        ix = kx;
        i__2 = *m;

        for (i__ = 1; i__ <= i__2; ++i__) {
            temp += a[i__ + j * a_dim1] * x[ix];
            if (j + 1 <= i__1) {
                temp2 += a[i__ + (j+1) * a_dim1] * x[ix];
            }
            ix += *incx;
        }

        y[jy] += *alpha * temp;

        if (j + 1 <= i__1) {
            y[jy + *incy] += *alpha * temp2;
        }

        jy += *incy * ((j + 1 <= i__1) ? 2 : 1); // Advance jy accordingly
    }
}
