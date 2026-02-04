#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = *m; j >= 3; --j) {
    a[j * a_dim1 + 1] = 0.F;
    a[(j-1) * a_dim1 + 1] = 0.F;
    i__1 = *m;
    for (i__ = j + 1; i__ <= i__1; ++i__) {
        a[i__ + j * a_dim1] = a[i__ + (j - 1) * a_dim1];
        a[i__ + (j-1) * a_dim1] = a[i__ + (j - 2) * a_dim1];
    }
}
}
