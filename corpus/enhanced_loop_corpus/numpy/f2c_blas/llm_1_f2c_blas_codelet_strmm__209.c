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
    i__3 = *n;
    for (k = j; k <= i__3; ++k) {
        if (k == j) {
            for (i__ = 1; i__ <= i__2; ++i__) {
                b[i__ + j * b_dim1] = temp * b[i__ + j * b_dim1];
            }
        } else {
            if (a[k + j * a_dim1] != 0.F) {
                temp = *alpha * a[k + j * a_dim1];
                for (i__ = 1; i__ <= i__2; ++i__) {
                    b[i__ + j * b_dim1] += temp * b[i__ + k * b_dim1];
                }
            }
        }
    }
}
}
