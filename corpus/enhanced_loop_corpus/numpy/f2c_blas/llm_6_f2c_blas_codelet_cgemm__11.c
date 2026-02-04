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
extern singlecomplex *alpha;
extern singlecomplex *a;
extern singlecomplex *b;
extern singlecomplex *beta;
extern singlecomplex *c__;
extern integer a_dim1;
extern integer b_dim1;
extern integer c_dim1;
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
extern integer l;
extern singlecomplex temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    int scale_c = !(beta->r == 0.F && beta->i == 0.F);
    i__2 = *m;
    for (i__ = 1; i__ <= i__2; ++i__) {
        i__3 = i__ + j * c_dim1;
        if (!scale_c) {
            c__[i__3].r = 0.F;
            c__[i__3].i = 0.F;
        } else if (beta->r != 1.F || beta->i != 0.F) {
            i__4 = i__ + j * c_dim1;
            q__1.r = beta->r * c__[i__4].r - beta->i * c__[i__4].i;
            q__1.i = beta->r * c__[i__4].i + beta->i * c__[i__4].r;
            c__[i__3].r = q__1.r;
            c__[i__3].i = q__1.i;
        }
    }
    i__2 = *k;
    for (l = 1; l <= i__2; ++l) {
        i__3 = j + l * b_dim1;
        singlecomplex b_val = b[i__3];
        if (b_val.r != 0.F || b_val.i != 0.F) {
            q__1.r = alpha->r * b_val.r - alpha->i * b_val.i;
            q__1.i = alpha->r * b_val.i + alpha->i * b_val.r;
            temp = q__1;
            i__3 = *m;
            for (i__ = 1; i__ <= i__3; ++i__) {
                i__4 = i__ + j * c_dim1;
                i__6 = i__ + l * a_dim1;
                q__2.r = temp.r * a[i__6].r - temp.i * a[i__6].i;
                q__2.i = temp.r * a[i__6].i + temp.i * a[i__6].r;
                c__[i__4].r += q__2.r;
                c__[i__4].i += q__2.i;
            }
        }
    }
}
}
