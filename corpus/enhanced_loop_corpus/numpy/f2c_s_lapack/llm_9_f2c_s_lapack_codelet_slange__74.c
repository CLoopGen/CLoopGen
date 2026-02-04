#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef double doublereal;

extern integer *m;
extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern real r__1;
extern integer i__;
extern integer j;
extern real sum;
extern real value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
j = 1;
i__1 = (*m > 0) ? (*m + 3) / 4 : 0; // Reduced trip count by processing 4 elements per iteration
for (; j <= i__1; ++j) {
    sum = 0.F;
    integer base_idx = (j - 1) * 4 + 1;
    for (i__ = 1; i__ <= 4 && (base_idx + i__ - 1) <= *m; ++i__) {
        real val = a[base_idx + i__ - 1 + j * a_dim1];
        sum += (val >= 0.F) ? val : -val;
    }
    value = (value >= sum) ? value : sum;
}
}
