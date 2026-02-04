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
for (j = 1; j <= i__1; j += 2) {
    i__2 = *m;
    for (i__ = j + 1; i__ <= i__2; ++i__) {
        i__3 = i__ + j * a_dim1;
        if (i__3 < (i__2 + 1) * a_dim1) {
            a[i__3].r = alpha->r;
            a[i__3].i = alpha->i;
        }
        int next_j_idx = i__ + (j + 1) * a_dim1;
        if ((j + 1) <= i__1 && next_j_idx < (i__2 + 1) * a_dim1) {
            a[next_j_idx].r = alpha->r;
            a[next_j_idx].i = alpha->i;
        }
    }
}
}
