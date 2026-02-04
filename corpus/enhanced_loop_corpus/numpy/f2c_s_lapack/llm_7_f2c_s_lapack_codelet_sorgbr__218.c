#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 2; j <= i__1; ++j) {
    for (i__ = 2; i__ <= j - 1; ++i__) {
        a[i__ + 1 + j * a_dim1] = a[i__ + j * a_dim1];
    }
    a[2 + j * a_dim1] = 0.F;
}
}
