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
    for (k = 1; k <= i__2; ++k) {
        integer bj_idx = j * b_dim1 + k;
        integer akk_idx = k * a_dim1 + k;
        if (b[bj_idx] != 0.) {
            temp = *alpha * b[bj_idx];
            i__3 = k - 1;
            for (i__ = 1; i__ <= i__3; ++i__) {
                integer bi_idx = i__ + j * b_dim1;
                integer aik_idx = i__ + k * a_dim1;
                b[bi_idx] += temp * a[aik_idx];
            }
            if (nounit) {
                temp *= a[akk_idx];
            }
            b[bj_idx] = temp;
        }
    }
}
}
