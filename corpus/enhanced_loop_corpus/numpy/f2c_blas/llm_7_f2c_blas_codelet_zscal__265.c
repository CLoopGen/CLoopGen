#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

extern doublecomplex *za;
extern doublecomplex *zx;
extern integer *incx;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern doublecomplex z__1;
extern integer i__;
extern integer ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    integer base_index = ix;
    for (i__ = 0; i__ < i__1; ++i__) {
        integer current_index = base_index + i__ * (*incx);
        doublecomplex product;
        product.r = za->r * zx[current_index].r - za->i * zx[current_index].i;
        product.i = za->r * zx[current_index].i + za->i * zx[current_index].r;
        zx[current_index].r = product.r;
        zx[current_index].i = product.i;
    }
    ix = base_index + i__1 * (*incx);
}
