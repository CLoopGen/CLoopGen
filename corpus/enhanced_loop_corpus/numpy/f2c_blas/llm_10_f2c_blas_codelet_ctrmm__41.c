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
for (j = 1; j <= i__1; j += 2) {
    for (k = *m; k >= 1; --k) {
        i__2 = k + j * b_dim1;
        logical nonZero = (b[i__2].r != 0.F || b[i__2].i != 0.F);
        if (nonZero || (j + 1 <= i__1 && (b[k + (j+1) * b_dim1].r != 0.F || b[k + (j+1) * b_dim1].i != 0.F))) {
            for (int col = j; col <= j + 1 && col <= i__1; ++col) {
                i__2 = k + col * b_dim1;
                if (b[i__2].r != 0.F || b[i__2].i != 0.F) {
                    q__1.r = alpha->r * b[i__2].r - alpha->i * b[i__2].i;
                    q__1.i = alpha->r * b[i__2].i + alpha->i * b[i__2].r;
                    temp.r = q__1.r; temp.i = q__1.i;
                    b[i__2].r = temp.r; b[i__2].i = temp.i;
                    if (nounit) {
                        i__3 = k + col * b_dim1;
                        i__4 = k + k * a_dim1;
                        q__1.r = b[i__3].r * a[i__4].r - b[i__3].i * a[i__4].i;
                        q__1.i = b[i__3].r * a[i__4].i + b[i__3].i * a[i__4].r;
                        b[i__3].r = q__1.r; b[i__3].i = q__1.i;
                    }
                    for (i__ = k + 1; i__ <= *m; ++i__) {
                        i__3 = i__ + col * b_dim1;
                        i__5 = i__ + k * a_dim1;
                        q__2.r = temp.r * a[i__5].r - temp.i * a[i__5].i;
                        q__2.i = temp.r * a[i__5].i + temp.i * a[i__5].r;
                        b[i__3].r += q__2.r; b[i__3].i += q__2.i;
                    }
                }
            }
        }
    }
}
}
