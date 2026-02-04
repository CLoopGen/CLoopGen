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
    if (nounit && a[j + j * a_dim1] != 0.F) {
        temp *= a[j + j * a_dim1];
    } else {
        temp = 0.F;
    }
    i__2 = *m;
    for (i__ = 1; i__ <= i__2; ++i__) {
        b[i__ + j * b_dim1] = temp * b[i__ + j * b_dim1];
    }
    i__2 = *n;
    for (k = j + 1; k <= i__2; ++k) {
        if (a[k + j * a_dim1] != 0.F) {
            temp = *alpha * a[k + j * a_dim1];
            i__3 = *m;
            for (i__ = 1; i__ <= i__3; ++i__) {
                real bk = b[i__ + k * b_dim1];
                if (bk != 0.F) {
                    b[i__ + j * b_dim1] += temp * bk;
                }
            }
        }
    }
}
}
