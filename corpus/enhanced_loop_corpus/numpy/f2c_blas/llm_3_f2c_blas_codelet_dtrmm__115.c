#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef int logical;

extern integer *m;
extern doublereal *alpha;
extern doublereal *a;
extern doublereal *b;
extern integer a_dim1;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;
extern integer k;
extern doublereal temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern with Reverse Iteration
    // Change iteration order to reverse (decreasing indices) and use strided access
    // to simulate different cache behavior and memory traversal patterns
    integer j_stride = b_dim1, i_stride = a_dim1;
    integer idx_b, idx_a;

    for (j = i__1; j >= 1; --j) {
        i__2 = *m;
        for (i__ = i__2; i__ >= 1; --i__) {
            idx_b = i__ + j * j_stride;
            temp = b[idx_b];
            if (nounit) {
                idx_a = i__ + i__ * i_stride;
                temp *= a[idx_a];
            }
            i__3 = *m;
            for (k = i__ + 1; k <= i__3; ++k) {
                idx_a = k + i__ * i_stride;
                idx_b = k + j * j_stride;
                temp += a[idx_a] * b[idx_b];
            }
            b[i__ + j * b_dim1] = *alpha * temp;
        }
    }
}
