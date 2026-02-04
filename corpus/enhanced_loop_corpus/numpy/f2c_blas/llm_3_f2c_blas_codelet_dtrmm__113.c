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
extern integer i__;
extern integer j;
extern integer k;
extern doublereal temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    integer base_b_col = j * b_dim1;
    for (k = *m; k >= 1; --k) {
        integer b_kj = k + base_b_col;
        if (b[b_kj] != 0.) {
            temp = *alpha * b[b_kj];
            b[b_kj] = temp;
            if (nounit) {
                b[b_kj] *= a[k + k * a_dim1];
            }
            i__2 = *m;
            integer base_a_col = k * a_dim1;
            for (i__ = k + 1; i__ <= i__2; ++i__) {
                b[i__ + base_b_col] += temp * a[i__ + base_a_col];
            }
        }
    }
}
}
