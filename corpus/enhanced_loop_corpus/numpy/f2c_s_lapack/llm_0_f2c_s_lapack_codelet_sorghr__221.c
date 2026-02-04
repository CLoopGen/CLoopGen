#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern integer *ihi;
extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = *ihi + 1; j <= i__1; ++j) {
    a[j + j * a_dim1] = 1.F;
    for (i__ = 1; i__ <= *n; ++i__) {
        a[i__ + j * a_dim1] = 0.F;
    }
}
}
