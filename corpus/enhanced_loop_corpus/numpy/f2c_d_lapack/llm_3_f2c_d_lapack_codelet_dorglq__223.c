#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *m;
extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer kk;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Modify access to be consecutive in memory by swapping loop order
    // Original loop iterates over rows inside columns. By interchanging loops,
    // we make memory accesses consecutive assuming column-major layout (Fortran-style).
    // This improves spatial locality and cache performance.
    if (*m >= kk + 1 && i__1 >= 1) {
        for (i__ = kk + 1; i__ <= *m; ++i__) {
            for (j = 1; j <= i__1; ++j) {
                a[i__ + j * a_dim1] = 0.;
            }
        }
    }
}
