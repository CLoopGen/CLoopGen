#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *alpha;
extern doublereal *a;
extern doublereal *x;
extern doublereal *y;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern doublereal temp1;
extern doublereal temp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    temp1 = *alpha * x[j];
    temp2 = 0.;
    i__2 = j - 1;
    ptrdiff_t base_idx_a = j * a_dim1;
    for (i__ = 1; i__ <= i__2; ++i__) {
        ptrdiff_t idx = i__ + base_idx_a;
        y[i__] += temp1 * a[idx];
        temp2 += a[idx] * x[i__];
    }
    y[j] += temp1 * a[j + j * a_dim1] + *alpha * temp2;
}
}
