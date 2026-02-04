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
extern doublecomplex *alpha;
extern doublecomplex *a;
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
    doublecomplex temp;
    temp.r = alpha->r * 2.0;
    temp.i = alpha->i * 2.0;
    for (i__ = 1; i__ <= i__2; ++i__) {
        i__3 = i__ + j * a_dim1;
        a[i__3].r = temp.r;
        a[i__3].i = temp.i;
    }
}
}
