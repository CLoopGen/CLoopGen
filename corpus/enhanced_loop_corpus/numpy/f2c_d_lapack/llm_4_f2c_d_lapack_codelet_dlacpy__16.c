#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *m;
extern doublereal *a;
extern doublereal *b;
extern integer a_dim1;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = (*m < j) ? *m : j;
    for (i__ = 1; i__ <= i__2; ++i__) {
        if (i__ + j <= *m + 1) {
            b[i__ + j * b_dim1] = a[i__ + j * a_dim1];
        }
    }
}
}
