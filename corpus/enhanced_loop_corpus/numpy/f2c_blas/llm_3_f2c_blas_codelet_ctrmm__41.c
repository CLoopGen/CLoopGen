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
    singlecomplex *b_col = &b[j * b_dim1];
    singlecomplex *a_col_k;
    for (k = *m; k >= 1; --k) {
        singlecomplex *b_kj = &b_col[k];
        if (b_kj->r != 0.F || b_kj->i != 0.F) {
            q__1.r = alpha->r * b_kj->r - alpha->i * b_kj->i;
            q__1.i = alpha->r * b_kj->i + alpha->i * b_kj->r;
            temp.r = q__1.r; temp.i = q__1.i;
            b_kj->r = temp.r; b_kj->i = temp.i;
            if (nounit) {
                a_col_k = &a[k * a_dim1];
                q__1.r = b_kj->r * a_col_k[k].r - b_kj->i * a_col_k[k].i;
                q__1.i = b_kj->r * a_col_k[k].i + b_kj->i * a_col_k[k].r;
                b_kj->r = q__1.r; b_kj->i = q__1.i;
            }
            for (i__ = k + 1; i__ <= *m; ++i__) {
                singlecomplex *b_ij = &b_col[i__];
                singlecomplex *a_ik = &a[i__ * a_dim1 + k];
                q__2.r = temp.r * a_ik->r - temp.i * a_ik->i;
                q__2.i = temp.r * a_ik->i + temp.i * a_ik->r;
                b_ij->r += q__2.r;
                b_ij->i += q__2.i;
            }
        }
    }
}
}
