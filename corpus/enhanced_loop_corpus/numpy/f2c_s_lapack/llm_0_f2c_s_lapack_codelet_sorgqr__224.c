#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer kk;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = kk + 1; j <= i__1; ++j) {
    for (i__ = 1; i__ <= kk; ++i__) {
        a[i__ + j * a_dim1] = 0.F;
    }
}
}
