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

extern singlecomplex *a;
extern integer *ipiv;
extern integer *incx;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__5;
extern integer i__6;
extern integer i__;
extern integer j;
extern integer k;
extern integer i1;
extern integer i2;
extern integer ip;
extern integer ix;
extern integer ix0;
extern integer inc;
extern singlecomplex temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; j += 32) {
    ix = ix0;
    i__2 = i2;
    i__3 = inc;
    for (i__ = i1; i__3 < 0 ? i__ >= i__2 : i__ <= i__2; i__ += i__3) {
        ip = ipiv[ix];
        if (ip != i__) {
            i__4 = j + 31;
            for (k = j; k <= i__4; ++k) {
                integer idx1 = i__ + k * a_dim1;
                integer idx2 = ip + k * a_dim1;
                temp.r = a[idx1].r; temp.i = a[idx1].i;
                a[idx1].r = a[idx2].r; a[idx1].i = a[idx2].i;
                a[idx2].r = temp.r; a[idx2].i = temp.i;
            }
        }
        ix += *incx;
    }
}
}
