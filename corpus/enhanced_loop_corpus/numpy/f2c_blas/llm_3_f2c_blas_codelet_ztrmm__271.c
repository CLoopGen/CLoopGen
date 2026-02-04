#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int logical;

extern integer *m;
extern doublecomplex *alpha;
extern doublecomplex *a;
extern doublecomplex *b;
extern integer a_dim1;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__5;
extern doublecomplex z__1;
extern doublecomplex z__2;
extern integer i__;
extern integer j;
extern integer k;
extern doublecomplex temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    doublecomplex *col_b = &b[j * b_dim1];
    doublecomplex *col_a = &a[0];
    for (k = *m; k >= 1; --k) {
        doublecomplex *b_kj = &col_b[k];
        if (b_kj->r != 0. || b_kj->i != 0.) {
            z__1.r = alpha->r * b_kj->r - alpha->i * b_kj->i;
            z__1.i = alpha->r * b_kj->i + alpha->i * b_kj->r;
            temp.r = z__1.r; temp.i = z__1.i;
            b_kj->r = temp.r; b_kj->i = temp.i;
            if (nounit) {
                doublecomplex *a_kk = &col_a[k + k * a_dim1];
                z__1.r = b_kj->r * a_kk->r - b_kj->i * a_kk->i;
                z__1.i = b_kj->r * a_kk->i + b_kj->i * a_kk->r;
                b_kj->r = z__1.r; b_kj->i = z__1.i;
            }
            for (i__ = k + 1; i__ <= *m; ++i__) {
                doublecomplex *b_ij = &col_b[i__];
                doublecomplex *a_ik = &col_a[i__ + k * a_dim1];
                z__2.r = temp.r * a_ik->r - temp.i * a_ik->i;
                z__2.i = temp.r * a_ik->i + temp.i * a_ik->r;
                b_ij->r += z__2.r;
                b_ij->i += z__2.i;
            }
        }
    }
}
}
