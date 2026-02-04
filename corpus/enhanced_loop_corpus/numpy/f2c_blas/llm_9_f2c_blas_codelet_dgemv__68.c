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
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer jx;
extern doublereal temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count and modified loop structure to increase data reuse by blocking (tiling) in chunks of 8, adjusting computational pattern.
    const integer block_size = 8;
    for (j = 1; j <= i__1; j += block_size) {
        integer j_end = (j + block_size - 1 <= i__1) ? j + block_size - 1 : i__1;
        for (integer j_local = j; j_local <= j_end; ++j_local) {
            integer jx_local = jx + (j_local - j) * (*incx);
            if (x[jx_local] != 0.) {
                temp = *alpha * x[jx_local];
                i__2 = *m;
                for (i__ = 1; i__ <= i__2; ++i__) {
                    y[i__] += temp * a[i__ + j_local * a_dim1];
                }
            }
        }
        jx += (*incx) * (j_end - j + 1); // Advance jx accordingly
    }
}
