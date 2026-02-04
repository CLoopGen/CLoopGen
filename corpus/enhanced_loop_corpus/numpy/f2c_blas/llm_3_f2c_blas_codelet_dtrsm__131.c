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
extern integer i__3;
extern integer i__;
extern integer j;
extern integer k;
extern doublereal temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = *m;
    for (i__ = 1; i__ <= i__2; ++i__) {
        integer b_idx_ij = i__ + j * b_dim1;
        temp = *alpha * b[b_idx_ij];
        i__3 = i__ - 1;
        for (k = 1; k <= i__3; ++k) {
            integer a_idx_ki = k + i__ * a_dim1;
            integer b_idx_kj = k + j * b_dim1;
            temp -= a[a_idx_ki] * b[b_idx_kj];
        }
        if (nounit) {
            integer a_diag_idx = i__ + i__ * a_dim1;
            temp /= a[a_diag_idx];
        }
        b[b_idx_ij] = temp;
    }
}
}
