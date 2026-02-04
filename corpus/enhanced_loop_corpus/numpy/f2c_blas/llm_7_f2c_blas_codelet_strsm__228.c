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
for (k = 1; k <= i__1; ++k) {
    real alpha_val = *alpha;
    real diag_inv = nounit ? (a[k + k * a_dim1] != 0.F ? 1.F / a[k + k * a_dim1] : 1.F) : 1.F;
    i__2 = *m;
    for (i__ = 1; i__ <= i__2; ++i__) {
        real scaled_val = b[i__ + k * b_dim1];
        if (nounit) {
            scaled_val *= diag_inv;
        }
        if (alpha_val != 1.F) {
            scaled_val *= alpha_val;
        }
        b[i__ + k * b_dim1] = scaled_val;
    }
    i__2 = *n;
    for (j = k + 1; j <= i__2; ++j) {
        if (a[j + k * a_dim1] != 0.F) {
            temp = a[j + k * a_dim1];
            i__3 = *m;
            for (i__ = 1; i__ <= i__3; ++i__) {
                b[i__ + j * b_dim1] -= temp * b[i__ + k * b_dim1];
            }
        }
    }
}
}
