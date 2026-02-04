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
doublereal temp_local;
for (j = 1; j <= i__1; ++j) {
    temp_local = 0.0;
    if (x[j] != 0.) {
        temp_local = x[j];
        i__2 = j - 1;
        for (i__ = 1; i__ <= i__2; ++i__) {
            x[i__] += temp_local * a[i__ + j * a_dim1];
        }
        if (nounit) {
            x[j] *= a[j + j * a_dim1];
        }
    }
    temp = temp_local;
}
}
