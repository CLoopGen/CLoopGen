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
extern integer i__;
extern integer j;
extern integer k;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = *n; k >= 1; --k) {
    i__1 = *n;
    for (j = k + 1; j <= i__1; ++j) {
        if (*(a + j + k * a_dim1) != 0.F) {
            temp = *alpha * *(a + j + k * a_dim1);
            i__2 = *m;
            for (i__ = 1; i__ <= i__2; ++i__) {
                *(b + i__ + j * b_dim1) += temp * *(b + i__ + k * b_dim1);
            }
        }
    }
    temp = *alpha;
    if (nounit) {
        temp *= *(a + k + k * a_dim1);
    }
    if (temp != 1.F) {
        i__1 = *m;
        for (i__ = 1; i__ <= i__1; ++i__) {
            *(b + i__ + k * b_dim1) = temp * *(b + i__ + k * b_dim1);
        }
    }
}
}
