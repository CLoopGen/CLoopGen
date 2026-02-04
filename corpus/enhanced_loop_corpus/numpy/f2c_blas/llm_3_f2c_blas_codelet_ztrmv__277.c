#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int logical;

extern integer *n;
extern doublecomplex *a;
extern doublecomplex *x;
extern integer *incx;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern doublecomplex z__1;
extern doublecomplex z__2;
extern integer i__;
extern integer j;
extern integer ix;
extern integer jx;
extern integer kx;
extern doublecomplex temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
integer stride = *incx;
for (j = *n; j >= 1; --j) {
    integer j_offset = jx;
    if (x[j_offset].r != 0. || x[j_offset].i != 0.) {
        temp.r = x[j_offset].r; temp.i = x[j_offset].i;
        integer current_ix = kx;
        for (i__ = *n; i__ >= j + 1; --i__) {
            integer x_offset = current_ix;
            integer a_offset = i__ + j * a_dim1;
            z__2.r = temp.r * a[a_offset].r - temp.i * a[a_offset].i;
            z__2.i = temp.r * a[a_offset].i + temp.i * a[a_offset].r;
            z__1.r = x[x_offset].r + z__2.r;
            z__1.i = x[x_offset].i + z__2.i;
            x[x_offset].r = z__1.r; x[x_offset].i = z__1.i;
            current_ix -= stride;
        }
        if (nounit) {
            integer diag_a_offset = j + j * a_dim1;
            z__1.r = x[j_offset].r * a[diag_a_offset].r - x[j_offset].i * a[diag_a_offset].i;
            z__1.i = x[j_offset].r * a[diag_a_offset].i + x[j_offset].i * a[diag_a_offset].r;
            x[j_offset].r = z__1.r; x[j_offset].i = z__1.i;
        }
    }
    jx -= stride;
}
}
