#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef int logical;

extern integer *m;
extern integer *n;
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
for (j = 1; j <= i__1; ++j) {
    temp = *alpha;
    if (nounit) {
        temp *= a[j + j * a_dim1];
    }
    i__2 = *m;
    real *col_b_j = &b[j * b_dim1];
    for (i__ = 1; i__ <= i__2; ++i__) {
        col_b_j[i__] = temp * col_b_j[i__];
    }
    i__2 = *n;
    for (k = j + 1; k <= i__2; ++k) {
        real a_val = a[k + j * a_dim1];
        if (a_val != 0.F) {
            temp = *alpha * a_val;
            real *col_b_k = &b[k * b_dim1];
            i__3 = *m;
            for (i__ = 1; i__ <= i__3; ++i__) {
                col_b_j[i__] += temp * col_b_k[i__];
            }
        }
    }
}
}
