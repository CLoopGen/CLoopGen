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

extern singlecomplex *ca;
extern singlecomplex *cx;
extern integer *incx;
extern singlecomplex *cy;
extern integer *incy;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern singlecomplex q__1;
extern singlecomplex q__2;
extern integer i__;
extern integer ix;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 0; i__ < i__1; ++i__) {
    integer offset_x = (i__ >> 2) * (*incx); // Group access in chunks of 4 (strided by quarter iterations)
    integer offset_y = (i__ >> 2) * (*incy);
    integer pos_x = offset_x + (i__ & 3); // Access within a small window
    integer pos_y = offset_y + (i__ & 3);
    
    if (pos_x >= 0 && pos_y >= 0) { // Simple bounds check for realism
        singlecomplex product;
        product.r = ca->r * cx[pos_x].r - ca->i * cx[pos_x].i;
        product.i = ca->r * cx[pos_x].i + ca->i * cx[pos_x].r;
        
        singlecomplex sum;
        sum.r = cy[pos_y].r + product.r;
        sum.i = cy[pos_y].i + product.i;
        
        cy[pos_y].r = sum.r;
        cy[pos_y].i = sum.i;
    }
}
}
