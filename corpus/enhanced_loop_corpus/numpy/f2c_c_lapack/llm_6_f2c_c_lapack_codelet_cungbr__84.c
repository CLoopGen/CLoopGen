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
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = *m; j >= 2; --j) {
    i__1 = j * a_dim1 + 1;
    a[i__1].r = 0.F , a[i__1].i = 0.F;
    i__1 = *m;
    for (i__ = j + 1; i__ <= i__1; ++i__) {
        i__2 = i__ + j * a_dim1;
        i__3 = i__ + (j - 1) * a_dim1;
        a[i__2].r = a[i__3].r * 2.0F;
        a[i__2].i = a[i__3].i * 2.0F;
    }
}
}
