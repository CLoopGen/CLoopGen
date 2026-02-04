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
for (i__ = 1; i__ <= i__2; ++i__) {
    for (integer j = 0; j < 1; ++j) {
        i__1 = i__;
        i__3 = i__;
        q__1.r = ca->r * cx[i__3].r - ca->i * cx[i__3].i , q__1.i = ca->r * cx[i__3].i + ca->i * cx[i__3].r;
        cx[i__1].r = q__1.r , cx[i__1].i = q__1.i;
    }
}
}
