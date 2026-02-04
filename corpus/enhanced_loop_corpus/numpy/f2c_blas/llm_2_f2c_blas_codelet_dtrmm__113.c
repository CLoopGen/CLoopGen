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
    for (k = *m; k >= 1; --k) {
        integer b_index = k + j * b_dim1;
        if (b[b_index] != 0.) {
            temp = *alpha * b[b_index];
            b[b_index] = temp;
            if (nounit) {
                integer a_diag_index = k + k * a_dim1;
                b[b_index] *= a[a_diag_index];
            }
            i__2 = *m;
            for (i__ = k + 1; i__ <= i__2; ++i__) {
                integer b_update_index = i__ + j * b_dim1;
                integer a_val_index = i__ + k * a_dim1;
                b[b_update_index] += temp * a[a_val_index];
            }
        }
    }
}
}
