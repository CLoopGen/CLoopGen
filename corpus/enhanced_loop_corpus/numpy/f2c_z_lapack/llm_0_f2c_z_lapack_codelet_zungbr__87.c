#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

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
    i__2 = j * a_dim1 + 1;
    a[i__2].r = 0. , a[i__2].i = 0.;
    for (i__ = j - 1; i__ >= 2; --i__) {
        i__2 = i__ + j * a_dim1;
        i__3 = i__ - 1 + j * a_dim1;
        a[i__2].r = a[i__3].r , a[i__2].i = a[i__3].i;
    }
}
}
