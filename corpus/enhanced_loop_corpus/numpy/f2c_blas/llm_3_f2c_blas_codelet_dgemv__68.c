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
    // Variant 2: Strided memory access on vector y and indirect indexing on matrix a using row-major simulation
    for (j = 1; j <= i__1; ++j) {
        if (x[jx] != 0.) {
            temp = *alpha * x[jx];
            for (i__ = 1; i__ <= *m; ++i__) {
                // Simulate strided access on y with stride of 2, wrapping within bounds
                integer y_idx = (i__ % (*m)) + 1; // Indirect, permuted access to y
                y[y_idx] += temp * a[i__ + j * a_dim1]; // Original access to a remains unchanged
            }
        }
        jx += *incx;
    }
}
