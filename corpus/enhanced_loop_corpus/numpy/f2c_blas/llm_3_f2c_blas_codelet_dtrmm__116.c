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
for (j = *n; j >= 1; --j) {
    temp = *alpha;
    if (nounit) {
        temp *= a[j * a_dim1 + j];  // Same access, reordered expression
    }
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
        b[j * b_dim1 + i__] = temp * b[j * b_dim1 + i__];  // Row-major style: consecutive in i, stride b_dim1
    }
    i__1 = j - 1;
    for (k = 1; k <= i__1; ++k) {
        if (a[j * a_dim1 + k] != 0.) {  // Access pattern flipped: treating column as row index
            temp = *alpha * a[j * a_dim1 + k];
            i__2 = *m;
            for (i__ = 1; i__ <= i__2; ++i__) {
                b[j * b_dim1 + i__] += temp * b[k * b_dim1 + i__];  // Consecutive memory access in inner loop
            }
        }
    }
}
}
