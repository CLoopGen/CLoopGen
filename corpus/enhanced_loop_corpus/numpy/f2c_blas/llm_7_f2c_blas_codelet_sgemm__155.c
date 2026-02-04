#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
extern integer *k;
extern real *alpha;
extern real *a;
extern real *b;
extern real *beta;
extern real *c__;
extern integer a_dim1;
extern integer b_dim1;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;
extern integer l;
extern real temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Introduce loop interchange (j-loop moved inside i-loop) and restructure dependencies
// This removes some of the original loop-carried dependencies across i and increases locality in j
i__2 = *m;
for (i__ = 1; i__ <= i__2; ++i__) {
    real temp_local[256]; // Local accumulation per j to eliminate write-after-write (WAW) on c__
    for (j = 1; j <= i__1; ++j) {
        temp_local[j] = 0.F;
        i__3 = *k;
        for (l = 1; l <= i__3; ++l) {
            // Reorder computation: now i is fixed outer, increasing spatial reuse of row i of matrix a
            temp_local[j] += a[l + i__ * a_dim1] * b[j + l * b_dim1];
        }
    }
    // Now update c__ after full temp computation to break WAW and enable better vectorization
    for (j = 1; j <= i__1; ++j) {
        if (*beta == 0.F) {
            c__[i__ + j * c_dim1] = *alpha * temp_local[j];
        } else {
            c__[i__ + j * c_dim1] = *alpha * temp_local[j] + *beta * c__[i__ + j * c_dim1];
        }
    }
}
}
