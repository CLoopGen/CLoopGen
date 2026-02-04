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
for (j = 1; j <= i__1; ++j) {
    logical skip_scaling = (*alpha == 1.F);
    if (!skip_scaling) {
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            b[i__ + j * b_dim1] *= *alpha;
        }
    }
    i__2 = j - 1;
    for (k = 1; k <= i__2; ++k) {
        real akj = a[k + j * a_dim1];
        if (akj == 0.F) continue;
        i__3 = *m;
        for (i__ = 1; i__ <= i__3; ++i__) {
            b[i__ + j * b_dim1] -= akj * b[i__ + k * b_dim1];
        }
    }
    if (nounit && a[j + j * a_dim1] != 0.F) {
        temp = 1.F / a[j + j * a_dim1];
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            b[i__ + j * b_dim1] *= temp;
        }
    }
}
}
