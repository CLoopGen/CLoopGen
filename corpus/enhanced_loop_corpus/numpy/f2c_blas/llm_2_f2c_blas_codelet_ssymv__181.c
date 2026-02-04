#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
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
for (j = 1; j <= i__1; ++j) {
    temp1 = *alpha * x[j];
    temp2 = 0.F;
    y[j] += temp1 * a[j + j * a_dim1];
    i__2 = *n;
    for (i__ = j + 1; i__ <= i__2; ++i__) {
        int index = i__ + j * a_dim1; // Strided access via precomputed index
        y[i__] += temp1 * a[index];
        temp2 += a[index] * x[i__];
    }
    y[j] += *alpha * temp2;
}
}
