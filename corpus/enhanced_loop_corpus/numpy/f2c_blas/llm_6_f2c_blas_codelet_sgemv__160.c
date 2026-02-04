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
    real temp_cache[64]; // Local cache to remove write-after-write dependency on 'temp'
    integer k;
    for (j = 1; j <= i__1 && j <= 64; ++j) {
        temp_cache[j-1] = 0.F;
        if (x[jx] != 0.F) {
            temp_cache[j-1] = *alpha * x[jx];
            i__2 = *m;
            for (i__ = 1; i__ <= i__2; ++i__) {
                y[i__] += temp_cache[j-1] * a[i__ + j * a_dim1];
            }
        }
        jx += *incx;
    }
    // Introduce loop-carried dependence on jx through conditional update
    if (j <= i__1) {
        for (; j <= i__1; ++j) {
            real temp = (*alpha) * x[jx];
            i__2 = *m;
            for (i__ = 1; i__ <= i__2; ++i__) {
                y[i__] += temp * a[i__ + j * a_dim1];
            }
            jx += *incx;
        }
    }
}
