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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce effective trip count by half and increase stride for higher complexity per iteration
integer step = 2;
for (i__ = 1; i__ <= i__1; i__ += step) {
    i__2 = iy;
    i__3 = ix;
    // Perform two assignments per iteration if within bounds
    cy[i__2].r = cx[i__3].r;
    cy[i__2].i = cx[i__3].i;
    
    // Apply second operation only if next index is valid
    if (i__ + 1 <= i__1) {
        integer ix_next = ix + *incx;
        integer iy_next = iy + *incy;
        cy[iy_next].r = cx[ix_next].r;
        cy[iy_next].i = cx[ix_next].i;
    }
    
    ix += *incx * step;
    iy += *incy * step;
}
}
