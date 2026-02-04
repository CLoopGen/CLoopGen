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
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    if (*alpha != 1.F) {
        for (i__ = 1; i__ <= *m; ++i__) {
            b[i__ + j * b_dim1] = *alpha * b[i__ + j * b_dim1];
        }
    }
    for (k = 1; k <= *m; ++k) {
        if (b[k + j * b_dim1] != 0.F) {
            if (nounit) {
                b[k + j * b_dim1] /= a[k + k * a_dim1];
            }
            for (i__ = k + 1; i__ <= *m; ++i__) {
                b[i__ + j * b_dim1] -= b[k + j * b_dim1] * a[i__ + k * a_dim1];
            }
        }
    }
}
}
