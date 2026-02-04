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
extern singlecomplex q__1;
extern singlecomplex q__2;
extern integer i__;
extern integer j;
extern integer k;
extern singlecomplex temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const singlecomplex * restrict a_ptr = a;
singlecomplex * restrict b_ptr = b;
integer stride_b = b_dim1;
for (j = *n; j >= 1; --j) {
    temp.r = alpha->r;
    temp.i = alpha->i;
    if (nounit) {
        i__1 = j * (a_dim1 + 1);
        q__1.r = temp.r * a_ptr[i__1].r - temp.i * a_ptr[i__1].i;
        q__1.i = temp.r * a_ptr[i__1].i + temp.i * a_ptr[i__1].r;
        temp.r = q__1.r;
        temp.i = q__1.i;
    }
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
        integer idx_b = i__ + j * stride_b;
        q__1.r = temp.r * b_ptr[idx_b].r - temp.i * b_ptr[idx_b].i;
        q__1.i = temp.r * b_ptr[idx_b].i + temp.i * b_ptr[idx_b].r;
        b_ptr[idx_b].r = q__1.r;
        b_ptr[idx_b].i = q__1.i;
    }
    i__1 = j - 1;
    for (k = 1; k <= i__1; ++k) {
        i__2 = k + j * a_dim1;
        if (a_ptr[i__2].r != 0.F || a_ptr[i__2].i != 0.F) {
            i__2 = k + j * a_dim1;
            q__1.r = alpha->r * a_ptr[i__2].r - alpha->i * a_ptr[i__2].i;
            q__1.i = alpha->r * a_ptr[i__2].i + alpha->i * a_ptr[i__2].r;
            temp.r = q__1.r;
            temp.i = q__1.i;
            i__2 = *m;
            for (i__ = 1; i__ <= i__2; ++i__) {
                integer idx_j = i__ + j * stride_b;
                integer idx_k = i__ + k * stride_b;
                q__2.r = temp.r * b_ptr[idx_k].r - temp.i * b_ptr[idx_k].i;
                q__2.i = temp.r * b_ptr[idx_k].i + temp.i * b_ptr[idx_k].r;
                b_ptr[idx_j].r += q__2.r;
                b_ptr[idx_j].i += q__2.i;
            }
        }
    }
}
}
