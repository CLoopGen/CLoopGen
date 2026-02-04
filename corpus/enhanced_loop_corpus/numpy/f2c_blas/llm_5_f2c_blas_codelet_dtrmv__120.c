#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

typedef int logical;

extern doublereal *a;
extern doublereal *x;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern doublereal temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    if (x[j] == 0.) continue;
    temp = x[j];
    for (i__ = 1; i__ < j; ++i__) {
        x[i__] += temp * a[i__ + j * a_dim1];
    }
    if (nounit) {
        x[j] = temp * a[j + j * a_dim1];
    }
}
}
