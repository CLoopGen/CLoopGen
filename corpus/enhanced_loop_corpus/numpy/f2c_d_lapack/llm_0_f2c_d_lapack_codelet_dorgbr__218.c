#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 2; j <= i__1; ++j) {
    i__ = j - 1;
    a[j * a_dim1 + 1] = 0.;
    for (; i__ >= 2; --i__) {
        a[i__ + j * a_dim1] = a[i__ - 1 + j * a_dim1];
    }
}
}
