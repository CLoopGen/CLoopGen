#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef int logical;

extern real *a;
extern real *x;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Memory Access via Reordering
    // Reformulate the inner loop to access memory sequentially by precomputing
    // a temporary access pattern that improves spatial locality in array `a`.
    // We reverse the inner loop to promote better cache reuse when `a` is column-major.
    for (j = 1; j <= i__1; ++j) {
        if (x[j] != 0.F) {
            temp = x[j];
            i__2 = j - 1;
            // Reverse iteration for consecutive backward access in some views of `a`
            for (i__ = i__2; i__ >= 1; --i__) {
                // Access remains the same, but order reversed to improve cache line utilization
                // when prior operations favor recent column entries.
                x[i__] += temp * a[i__ + j * a_dim1];
            }
            if (nounit) {
                x[j] *= a[j + j * a_dim1];
            }
        }
    }
}
