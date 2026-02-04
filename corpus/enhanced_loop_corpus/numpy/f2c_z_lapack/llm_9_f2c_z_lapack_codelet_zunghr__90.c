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

extern integer *n;
extern integer *ihi;
extern doublecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = *ihi + 1; j <= i__1; j += 2) {
    i__2 = *n;
    for (i__ = 1; i__ <= i__2; ++i__) {
        i__3 = i__ + j * a_dim1;
        a[i__3].r = 0. , a[i__3].i = 0.;
    }
    i__2 = j + j * a_dim1;
    a[i__2].r = 1. , a[i__2].i = 0.;
    if (j + 1 <= i__1) {
        i__2 = j + 1 + (j + 1) * a_dim1;
        a[i__2].r = 1. , a[i__2].i = 0.;
        for (i__ = 1; i__ <= *n; ++i__) {
            i__3 = i__ + (j + 1) * a_dim1;
            a[i__3].r = 0. , a[i__3].i = 0.;
        }
    }
}
}
