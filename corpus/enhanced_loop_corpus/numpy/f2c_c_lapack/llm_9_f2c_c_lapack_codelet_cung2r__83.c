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
for (j = *k + 1; j <= i__1; j += 2) {
    i__2 = (*m > j) ? j : *m;
    for (l = 1; l <= i__2; ++l) {
        i__3 = l + j * a_dim1;
        a[i__3].r = 0.F;
        a[i__3].i = 0.F;
    }
    i__2 = j + j * a_dim1;
    a[i__2].r = 1.F;
    a[i__2].i = 0.F;

    if (j + 1 <= i__1) {
        i__2 = j + 1 + (j + 1) * a_dim1;
        a[i__2].r = 1.F;
        a[i__2].i = 0.F;
    }
}
}
