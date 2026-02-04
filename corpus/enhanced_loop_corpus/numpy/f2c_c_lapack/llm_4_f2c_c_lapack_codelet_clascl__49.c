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

extern integer *m;
extern singlecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern singlecomplex q__1;
extern integer i__;
extern integer j;
extern real mul;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = ((j) <= (*m) ? (j) : (*m));
    for (i__ = 1; i__ <= i__2; ++i__) {
        ptrdiff_t idx = (ptrdiff_t)(i__ - 1) + (ptrdiff_t)(j - 1) * a_dim1;
        q__1.r = mul * a[idx].r;
        q__1.i = mul * a[idx].i;
        a[idx].r = q__1.r;
        a[idx].i = q__1.i;
    }
}
}
