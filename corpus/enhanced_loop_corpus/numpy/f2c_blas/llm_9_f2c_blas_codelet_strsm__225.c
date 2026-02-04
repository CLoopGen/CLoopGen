#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef int logical;

extern integer *m;
extern real *alpha;
extern real *a;
extern real *b;
extern integer a_dim1;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;
extern integer k;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; j += 2) {
    i__2 = (j + 1 <= i__1) ? 2 : 1;
    for (int jj = 0; jj < i__2; ++jj) {
        int curr_j = j + jj;
        if (*alpha != 1.F) {
            i__3 = *m;
            for (i__ = 1; i__ <= i__3; ++i__) {
                b[i__ + curr_j * b_dim1] = *alpha * b[i__ + curr_j * b_dim1];
            }
        }
        i__3 = curr_j - 1;
        for (k = 1; k <= i__3; ++k) {
            if (a[k + curr_j * a_dim1] != 0.F) {
                i__1 = *m;
                for (i__ = 1; i__ <= i__1; ++i__) {
                    b[i__ + curr_j * b_dim1] -= a[k + curr_j * a_dim1] * b[i__ + k * b_dim1];
                }
            }
        }
        if (nounit && a[curr_j + curr_j * a_dim1] != 0.F) {
            temp = 1.F / a[curr_j + curr_j * a_dim1];
            i__3 = *m;
            for (i__ = 1; i__ <= i__3; ++i__) {
                b[i__ + curr_j * b_dim1] *= temp;
            }
        }
    }
}
}
