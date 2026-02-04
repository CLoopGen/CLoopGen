#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef int logical;

extern integer *n;
extern doublereal *a;
extern doublereal *x;
extern integer a_dim1;
extern integer i__;
extern integer j;
extern doublereal temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = *n; j >= 1; --j) {
    temp = x[j];
    if (nounit) {
        temp *= a[j + j * a_dim1];
    }
    i__ = j - 1;
    for (; i__ >= 1; --i__) {
        temp += a[i__ + j * a_dim1] * x[i__];
    }
    x[j] = temp;
}
}
