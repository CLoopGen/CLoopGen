#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

extern integer *m;
extern doublecomplex *a;
extern doublecomplex *b;
extern integer a_dim1;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = *m;
    for (i__ = 1; i__ <= i__2; ++i__) {
        i__3 = i__ + j * b_dim1;
        i__4 = i__ + j * a_dim1;
        // Introduce a temporary variable to create a write-after-write dependency
        // and break direct assignment: this adds intra-iteration WAW via temp usage
        doublecomplex temp;
        temp.r = a[i__4].r;
        temp.i = a[i__4].i;
        b[i__3].r = temp.r;
        b[i__3].i = temp.i;
    }
}
}
