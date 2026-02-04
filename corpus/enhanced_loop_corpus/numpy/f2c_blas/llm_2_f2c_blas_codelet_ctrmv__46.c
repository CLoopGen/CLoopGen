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

extern integer *n;
extern singlecomplex *a;
extern singlecomplex *x;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern singlecomplex q__1;
extern singlecomplex q__2;
extern integer i__;
extern integer j;
extern singlecomplex temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = *n; j >= 1; --j) {
    i__1 = j;
    if (x[i__1].r != 0.F || x[i__1].i != 0.F) {
        i__1 = j;
        temp.r = x[i__1].r , temp.i = x[i__1].i;
        i__1 = j + 1;
        for (i__ = *n; i__ >= i__1; --i__) {
            i__2 = i__;
            i__3 = i__;
            i__4 = j + i__ * a_dim1;  // Transposed access in matrix 'a': changed from A[i][j] to A[j][i] (column-major stride pattern)
            q__2.r = temp.r * a[i__4].r - temp.i * a[i__4].i , q__2.i = temp.r * a[i__4].i + temp.i * a[i__4].r;
            q__1.r = x[i__3].r + q__2.r , q__1.i = x[i__3].i + q__2.i;
            x[i__2].r = q__1.r , x[i__2].i = q__1.i;
        }
        if (nounit) {
            i__1 = j;
            i__2 = j;
            i__3 = j + j * a_dim1;
            q__1.r = x[i__2].r * a[i__3].r - x[i__2].i * a[i__3].i , q__1.i = x[i__2].r * a[i__3].i + x[i__2].i * a[i__3].r;
            x[i__1].r = q__1.r , x[i__1].i = q__1.i;
        }
    }
}
}
