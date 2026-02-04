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
    i__2 = *m;
    for (k = 1; k <= i__2; ++k) {
        i__3 = k + j * b_dim1;
        singlecomplex temp_local = {0.0F, 0.0F};
        int index_active = (b[i__3].r != 0.F || b[i__3].i != 0.F);
        if (index_active) {
            i__3 = k + j * b_dim1;
            q__1.r = alpha->r * b[i__3].r - alpha->i * b[i__3].i;
            q__1.i = alpha->r * b[i__3].i + alpha->i * b[i__3].r;
            temp_local.r = q__1.r;
            temp_local.i = q__1.i;
            i__3 = k - 1;
            for (i__ = 1; i__ <= i__3; ++i__) {
                i__6 = i__ + k * a_dim1;
                i__4 = i__ + j * b_dim1;
                q__2.r = temp_local.r * a[i__6].r - temp_local.i * a[i__6].i;
                q__2.i = temp_local.r * a[i__6].i + temp_local.i * a[i__6].r;
                b[i__4].r += q__2.r;
                b[i__4].i += q__2.i;
            }
            if (nounit) {
                i__3 = k + k * a_dim1;
                q__1.r = temp_local.r * a[i__3].r - temp_local.i * a[i__3].i;
                q__1.i = temp_local.r * a[i__3].i + temp_local.i * a[i__3].r;
                temp_local.r = q__1.r;
                temp_local.i = q__1.i;
            }
            i__3 = k + j * b_dim1;
            b[i__3].r = temp_local.r;
            b[i__3].i = temp_local.i;
        }
    }
}
}
