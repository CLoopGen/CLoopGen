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
    for (k = *m; k >= 1; --k) {
        ptrdiff_t b_idx = k + j * b_dim1;
        if (b[b_idx].r != 0.F || b[b_idx].i != 0.F) {
            q__1.r = alpha->r * b[b_idx].r - alpha->i * b[b_idx].i;
            q__1.i = alpha->r * b[b_idx].i + alpha->i * b[b_idx].r;
            temp.r = q__1.r; temp.i = q__1.i;
            b[b_idx].r = temp.r; b[b_idx].i = temp.i;
            if (nounit) {
                ptrdiff_t a_idx = k + k * a_dim1;
                q__1.r = b[b_idx].r * a[a_idx].r - b[b_idx].i * a[a_idx].i;
                q__1.i = b[b_idx].r * a[a_idx].i + b[b_idx].i * a[a_idx].r;
                b[b_idx].r = q__1.r; b[b_idx].i = q__1.i;
            }
            for (i__ = k + 1; i__ <= *m; ++i__) {
                ptrdiff_t b_idx1 = i__ + j * b_dim1;
                ptrdiff_t a_idx = i__ + k * a_dim1;
                q__2.r = temp.r * a[a_idx].r - temp.i * a[a_idx].i;
                q__2.i = temp.r * a[a_idx].i + temp.i * a[a_idx].r;
                b[b_idx1].r += q__2.r;
                b[b_idx1].i += q__2.i;
            }
        }
    }
}
}
