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
extern singlecomplex q__1;
extern singlecomplex q__2;
extern integer i__;
extern integer ix;
extern integer iy;
extern singlecomplex ctemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 0; i__ < i__1; ++i__) {
    int index_x = i__ * (*incx); // Strided access for cx
    int index_y = i__ * (*incy); // Strided access for cy
    singlecomplex temp;
    temp.r = cx[index_x].r * cy[index_y].r - cx[index_x].i * cy[index_y].i;
    temp.i = cx[index_x].r * cy[index_y].i + cx[index_x].i * cy[index_y].r;
    ctemp.r += temp.r;
    ctemp.i += temp.i;
}
}
