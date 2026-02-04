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
    if (x[j] != 0.F) {
        temp = x[j];
        i__2 = j - 1;
        for (i__ = 1; i__ <= i__2; ++i__) {
            real product = temp * a[i__ + j * a_dim1];
            x[i__] = x[i__] + product;
        }
        if (nounit) {
            x[j] = temp * a[j + j * a_dim1];
        }
    }
}
}
