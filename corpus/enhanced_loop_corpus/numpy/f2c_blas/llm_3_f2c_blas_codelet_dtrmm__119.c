#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef int logical;

extern integer *m;
extern integer *n;
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
for (k = *n; k >= 1; --k) {
    ptrdiff_t k_a_offset = k * a_dim1;
    ptrdiff_t k_b_offset = k * b_dim1;
    i__1 = *n;
    for (j = k + 1; j <= i__1; ++j) {
        ptrdiff_t j_a_offset = j + k_a_offset;
        if (a[j_a_offset] != 0.) {
            temp = *alpha * a[j_a_offset];
            i__2 = *m;
            ptrdiff_t j_b_offset = j * b_dim1;
            for (i__ = 1; i__ <= i__2; ++i__) {
                b[i__ + j_b_offset] += temp * b[i__ + k_b_offset];
            }
        }
    }
    temp = *alpha;
    if (nounit) {
        temp *= a[k + k_a_offset];
    }
    if (temp != 1.) {
        i__1 = *m;
        for (i__ = 1; i__ <= i__1; ++i__) {
            b[i__ + k_b_offset] = temp * b[i__ + k_b_offset];
        }
    }
}
}
