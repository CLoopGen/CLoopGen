#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern integer *ihi;
extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = *ihi + 1; j <= i__1; ++j) {
    i__2 = *n;
    for (i__ = i__2; i__ >= 1; --i__) {
        a[j * a_dim1 + i__] = 0.;
    }
    a[j * a_dim1 + j] = 1.;
}
}
