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
for (k = 1; k <= *m; ++k) {
    real a_diag = nounit ? a[k + k * a_dim1] : 1.0F;
    for (j = 1; j <= i__1; ++j) {
        integer b_idx = k + j * b_dim1;
        if (b[b_idx] != 0.F) {
            temp = *alpha * b[b_idx];
            for (i__ = 1; i__ <= k - 1; ++i__) {
                integer b_i_idx = i__ + j * b_dim1;
                integer a_ik_idx = i__ + k * a_dim1;
                b[b_i_idx] = b[b_i_idx] + temp * a[a_ik_idx];
            }
            b[b_idx] = temp * a_diag;
        }
    }
}
}
