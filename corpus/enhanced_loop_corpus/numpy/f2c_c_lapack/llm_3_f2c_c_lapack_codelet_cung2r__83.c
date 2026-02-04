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
for (j = *k + 1; j <= i__1; ++j) {
    i__2 = *m;
    integer base_j = j * a_dim1;
    for (l = 1; l <= i__2; ++l) {
        singlecomplex* addr = &a[l + base_j]; // Base address calculation hoisted and consecutive field assignment
        addr->r = 0.F;
        addr->i = 0.F;
    }
    a[j + j * a_dim1].r = 1.F;
    a[j + j * a_dim1].i = 0.F;
}
}
