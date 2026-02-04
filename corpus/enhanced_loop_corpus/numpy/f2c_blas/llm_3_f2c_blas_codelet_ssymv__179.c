#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *alpha;
extern real *a;
extern real *x;
extern real *y;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern real temp1;
extern real temp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reverse the iteration order over i to change memory access pattern to descending
for (j = 1; j <= i__1; ++j) {
    temp1 = *alpha * x[j];
    temp2 = 0.F;
    i__2 = j - 1;
    for (i__ = i__2; i__ >= 1; --i__) {
        // Access arrays in reverse order, promoting different cache behavior
        y[i__] += temp1 * a[i__ + j * a_dim1];
        temp2 += a[i__ + j * a_dim1] * x[i__];
    }
    y[j] = y[j] + temp1 * a[j + j * a_dim1] + *alpha * temp2;
}
}
