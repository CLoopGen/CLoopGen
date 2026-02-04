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
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = *ihi + 1; j <= i__1; ++j) {
    i__2 = *n;
    for (i__ = i__2; i__ >= 1; --i__) {
        i__3 = i__ + j * a_dim1;
        a[i__3].r = 0.F , a[i__3].i = 0.F;
    }
    i__2 = j + j * a_dim1;
    a[i__2].r = 1.F , a[i__2].i = 0.F;
}
}
