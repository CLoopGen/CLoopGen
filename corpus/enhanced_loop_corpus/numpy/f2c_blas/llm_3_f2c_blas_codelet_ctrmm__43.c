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

typedef int logical;

extern integer *m;
extern integer *n;
extern singlecomplex *alpha;
extern singlecomplex *a;
extern singlecomplex *b;
extern integer a_dim1;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__5;
extern integer i__6;
extern singlecomplex q__1;
extern singlecomplex q__2;
extern integer i__;
extern integer j;
extern integer k;
extern singlecomplex temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    temp.r = alpha->r , temp.i = alpha->i;
    if (nounit) {
        i__2 = j + j * a_dim1;
        q__1.r = temp.r * a[i__2].r - temp.i * a[i__2].i , q__1.i = temp.r * a[i__2].i + temp.i * a[i__2].r;
        temp.r = q__1.r , temp.i = q__1.i;
    }
    i__2 = *m;
    for (i__ = 1; i__ <= i__2; ++i__) {
        ptrdiff_t idx_b = (ptrdiff_t)(i__) + (ptrdiff_t)(j) * (ptrdiff_t)(b_dim1);
        q__1.r = temp.r * b[idx_b].r - temp.i * b[idx_b].i;
        q__1.i = temp.r * b[idx_b].i + temp.i * b[idx_b].r;
        b[idx_b].r = q__1.r;
        b[idx_b].i = q__1.i;
    }
    i__2 = *n;
    for (k = j + 1; k <= i__2; ++k) {
        ptrdiff_t idx_a = (ptrdiff_t)(k) + (ptrdiff_t)(j) * (ptrdiff_t)(a_dim1);
        if (a[idx_a].r != 0.F || a[idx_a].i != 0.F) {
            q__1.r = alpha->r * a[idx_a].r - alpha->i * a[idx_a].i;
            q__1.i = alpha->r * a[idx_a].i + alpha->i * a[idx_a].r;
            temp.r = q__1.r;
            temp.i = q__1.i;
            i__3 = *m;
            for (i__ = 1; i__ <= i__3; ++i__) {
                ptrdiff_t idx_j = (ptrdiff_t)(i__) + (ptrdiff_t)(j) * (ptrdiff_t)(b_dim1);
                ptrdiff_t idx_k = (ptrdiff_t)(i__) + (ptrdiff_t)(k) * (ptrdiff_t)(b_dim1);
                q__2.r = temp.r * b[idx_k].r - temp.i * b[idx_k].i;
                q__2.i = temp.r * b[idx_k].i + temp.i * b[idx_k].r;
                q__1.r = b[idx_j].r + q__2.r;
                q__1.i = b[idx_j].i + q__2.i;
                b[idx_j].r = q__1.r;
                b[idx_j].i = q__1.i;
            }
        }
    }
}
}
