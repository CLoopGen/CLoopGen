#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

typedef int logical;

extern singlecomplex *a;
extern singlecomplex *x;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__5;
extern singlecomplex q__1;
extern singlecomplex q__2;
extern integer i__;
extern integer j;
extern singlecomplex temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
singlecomplex *x_base = &x[1];
singlecomplex *a_col_start = &a[1 + 1 * a_dim1];
for (j = 1; j <= i__1; ++j) {
    if (x_base[j-1].r != 0.F || x_base[j-1].i != 0.F) {
        temp = x_base[j-1];
        const singlecomplex *a_col_j = &a[j * a_dim1];
        for (i__ = 1; i__ <= j - 1; ++i__) {
            singlecomplex a_val = a_col_j[i__];
            q__2.r = temp.r * a_val.r - temp.i * a_val.i;
            q__2.i = temp.r * a_val.i + temp.i * a_val.r;
            x_base[i__-1].r += q__2.r;
            x_base[i__-1].i += q__2.i;
        }
        if (nounit) {
            singlecomplex diag = a_col_j[j];
            x_base[j-1].r = temp.r * diag.r - temp.i * diag.i;
            x_base[j-1].i = temp.r * diag.i + temp.i * diag.r;
        }
    }
}
}
