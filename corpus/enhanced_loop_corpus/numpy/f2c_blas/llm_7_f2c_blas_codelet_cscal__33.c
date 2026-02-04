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
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern singlecomplex q__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
singlecomplex temp;
for (i__ = 1; i__2 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += i__2) {
    i__3 = i__;
    i__4 = i__;
    temp.r = cx[i__4].r;
    temp.i = cx[i__4].i;
    q__1.r = ca->r * temp.r - ca->i * temp.i;
    q__1.i = ca->r * temp.i + ca->i * temp.r;
    cx[i__3].r = q__1.r;
    cx[i__3].i = q__1.i;
}
}
