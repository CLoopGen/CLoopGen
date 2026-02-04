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
extern singlecomplex *alpha;
extern singlecomplex *a;
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
    for (i__ = 1; i__ <= i__2; i__ += 2) {
        if (i__ + j * a_dim1 < a_dim1 * (*m)) {
            a[i__ + j * a_dim1].r = alpha->r;
            a[i__ + j * a_dim1].i = alpha->i;
        }
        if (i__ + 1 <= i__2 && i__ + 1 + j * a_dim1 < a_dim1 * (*m)) {
            a[i__ + 1 + j * a_dim1].r = alpha->r;
            a[i__ + 1 + j * a_dim1].i = alpha->i;
        }
    }
}
}
