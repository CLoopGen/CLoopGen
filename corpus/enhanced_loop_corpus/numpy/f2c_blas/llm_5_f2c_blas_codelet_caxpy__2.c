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
extern singlecomplex *cy;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern singlecomplex q__1;
extern singlecomplex q__2;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1; ++i__) {
    i__2 = i__;
    i__3 = i__;
    i__4 = i__;
    if (cx[i__4].r != 0.0f || cx[i__4].i != 0.0f) {
        q__2.r = ca->r * cx[i__4].r - ca->i * cx[i__4].i , q__2.i = ca->r * cx[i__4].i + ca->i * cx[i__4].r;
        q__1.r = cy[i__3].r + q__2.r , q__1.i = cy[i__3].i + q__2.i;
        cy[i__2].r = q__1.r , cy[i__2].i = q__1.i;
    }
}
}
