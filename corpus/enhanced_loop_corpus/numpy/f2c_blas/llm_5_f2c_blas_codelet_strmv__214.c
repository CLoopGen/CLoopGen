#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef int logical;

extern integer *n;
extern real *a;
extern real *x;
extern integer a_dim1;
extern integer i__1;
extern integer i__;
extern integer j;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = *n; j >= 1; --j) {
    if (x[j] == 0.F) continue;
    temp = x[j];
    i__1 = j + 1;
    for (i__ = *n; i__ >= i__1; --i__) {
        real coeff = a[i__ + j * a_dim1];
        if (coeff != 0.F) {
            x[i__] += temp * coeff;
        }
    }
    if (nounit) {
        x[j] = temp * a[j + j * a_dim1];
    }
}
}
