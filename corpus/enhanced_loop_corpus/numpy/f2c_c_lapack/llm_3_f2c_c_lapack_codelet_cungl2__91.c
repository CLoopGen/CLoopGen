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
extern integer *k;
extern singlecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer j;
extern integer l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
integer stride = a_dim1 + 1;
for (j = 1; j <= i__1; ++j) {
    i__2 = *m;
    integer base_j = j * a_dim1;
    for (l = *k + 1; l <= i__2; ++l) {
        a[base_j + l].r = 0.F;
        a[base_j + l].i = 0.F;
    }
    if (j > *k && j <= *m) {
        a[j * stride].r = 1.F;
        a[j * stride].i = 0.F;
    }
}
}
