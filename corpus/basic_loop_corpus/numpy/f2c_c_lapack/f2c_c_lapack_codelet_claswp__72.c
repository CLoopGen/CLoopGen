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
                i__5 = i__ + k * a_dim1;
                temp.r = a[i__5].r , temp.i = a[i__5].i;
                i__5 = i__ + k * a_dim1;
                i__6 = ip + k * a_dim1;
                a[i__5].r = a[i__6].r , a[i__5].i = a[i__6].i;
                i__5 = ip + k * a_dim1;
                a[i__5].r = temp.r , a[i__5].i = temp.i;
            }
        }
        ix += *incx;
    }
}

}
