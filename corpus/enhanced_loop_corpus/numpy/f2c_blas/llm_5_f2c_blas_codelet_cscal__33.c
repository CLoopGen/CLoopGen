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
    for (i__ = 1; i__2 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += i__2) {
        i__3 = i__;
        i__4 = i__;
        if (cx[i__4].r > 0.0f || cx[i__4].i < 0.0f) {
            q__1.r = ca->r * cx[i__4].r - ca->i * cx[i__4].i;
            q__1.i = ca->r * cx[i__4].i + ca->i * cx[i__4].r;
            cx[i__3].r = q__1.r;
            cx[i__3].i = q__1.i;
        } else {
            cx[i__3].r *= 2.0f;
            cx[i__3].i *= 2.0f;
        }
    }
}
