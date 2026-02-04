#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *m;
extern doublereal *alpha;
extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 2; j <= i__1; ++j) {
    i__3 = j - 1;
    i__2 = ((i__3) <= (*m) ? (i__3) : (*m));
    for (i__ = i__2; i__ >= 1; --i__) {
        a[i__ + j * a_dim1] = *alpha;
    }
}
}
