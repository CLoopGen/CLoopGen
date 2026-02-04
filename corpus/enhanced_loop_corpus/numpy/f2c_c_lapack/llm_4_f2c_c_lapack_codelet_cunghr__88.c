#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

extern integer *n;
extern integer *ihi;
extern singlecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = *ihi; j >= i__1; --j) {
    singlecomplex *a_col_j = &a[j * a_dim1];
    singlecomplex *a_col_jm1 = &a[(j - 1) * a_dim1];
    for (i__ = 1; i__ <= j - 1; ++i__) {
        a_col_j[i__].r = 0.F , a_col_j[i__].i = 0.F;
    }
    for (i__ = j + 1; i__ <= *ihi; ++i__) {
        a_col_j[i__].r = a_col_jm1[i__].r , a_col_j[i__].i = a_col_jm1[i__].i;
    }
    for (i__ = *ihi + 1; i__ <= *n; ++i__) {
        a_col_j[i__].r = 0.F , a_col_j[i__].i = 0.F;
    }
}
}
