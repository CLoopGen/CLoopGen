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
    integer cj_base = j * c_dim1;
    if (beta->r == 0.F && beta->i == 0.F) {
        for (i__ = 1; i__ <= *m; ++i__) {
            c__[i__ + cj_base].r = 0.F;
            c__[i__ + cj_base].i = 0.F;
        }
    } else if (beta->r != 1.F || beta->i != 0.F) {
        for (i__ = 1; i__ <= *m; ++i__) {
            integer idx_c = i__ + cj_base;
            q__1.r = beta->r * c__[idx_c].r - beta->i * c__[idx_c].i;
            q__1.i = beta->r * c__[idx_c].i + beta->i * c__[idx_c].r;
            c__[idx_c].r = q__1.r;
            c__[idx_c].i = q__1.i;
        }
    }
    for (l = 1; l <= *k; ++l) {
        integer bj_idx = l + j * b_dim1;
        if (b[bj_idx].r != 0.F || b[bj_idx].i != 0.F) {
            q__1.r = alpha->r * b[bj_idx].r - alpha->i * b[bj_idx].i;
            q__1.i = alpha->r * b[bj_idx].i + alpha->i * b[bj_idx].r;
            temp.r = q__1.r;
            temp.i = q__1.i;
            for (i__ = 1; i__ <= *m; ++i__) {
                integer ci_idx = i__ + cj_base;
                integer ai_idx = i__ + l * a_dim1;
                q__2.r = temp.r * a[ai_idx].r - temp.i * a[ai_idx].i;
                q__2.i = temp.r * a[ai_idx].i + temp.i * a[ai_idx].r;
                c__[ci_idx].r += q__2.r;
                c__[ci_idx].i += q__2.i;
            }
        }
    }
}
}
