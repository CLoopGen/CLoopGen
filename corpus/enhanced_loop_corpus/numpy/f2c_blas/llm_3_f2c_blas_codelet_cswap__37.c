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

extern singlecomplex *cx;
extern integer *incx;
extern singlecomplex *cy;
extern integer *incy;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer ix;
extern integer iy;
extern singlecomplex ctemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Change memory access pattern to use strided access with fixed increment of 2
// Simulating a more regular, strided traversal independent of incx/incy for variation
integer stride = 2;
for (i__ = 0; i__ < i__1; ++i__) {
    i__2 = ix + i__ * stride;
    i__3 = iy + i__ * stride;
    // Ensure accesses are within bounds by modulo-like index folding (simulates indirect-like access)
    integer idx_x = (i__2) % (i__1 * abs(*incx)); 
    integer idx_y = (i__3) % (i__1 * abs(*incy)); 

    ctemp.r = cx[idx_x].r; ctemp.i = cx[idx_x].i;
    cx[idx_x].r = cy[idx_y].r; cx[idx_x].i = cy[idx_y].i;
    cy[idx_y].r = ctemp.r; cy[idx_y].i = ctemp.i;
}
}
