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
extern singlecomplex q__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
singlecomplex temp;
temp.r = cx[1].r;
temp.i = cx[1].i;
for (i__ = 1; i__ <= i__2; ++i__) {
    i__1 = i__;
    q__1.r = ca->r * temp.r - ca->i * temp.i;
    q__1.i = ca->r * temp.i + ca->i * temp.r;
    cx[i__1].r = q__1.r;
    cx[i__1].i = q__1.i;
    if (i__ < i__2) {
        temp.r = cx[i__+1].r;
        temp.i = cx[i__+1].i;
    }
}
}
