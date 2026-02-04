#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef int logical;

extern real *a;
extern real *x;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    real local_temp = x[j];
    if (local_temp != 0.F) {
        i__2 = j - 1;
        for (i__ = 1; i__ <= i__2; ++i__) {
            x[i__] += local_temp * a[i__ + j * a_dim1];
        }
        if (nounit) {
            x[j] = local_temp * a[j + j * a_dim1];
        }
    }
}
}
