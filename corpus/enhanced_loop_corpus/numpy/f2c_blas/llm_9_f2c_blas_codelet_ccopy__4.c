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
extern singlecomplex *cy;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1; i__ += 2) {
    i__2 = i__;
    i__3 = i__ + 1;
    if (i__3 <= i__1) {
        cy[i__2].r = cx[i__3].r * 0.5f + cx[i__].r * 0.5f;
        cy[i__2].i = cx[i__3].i * 0.5f + cx[i__].i * 0.5f;
        cy[i__3].r = cx[i__2].r * 0.5f + cx[i__3].r * 0.5f;
        cy[i__3].i = cx[i__2].i * 0.5f + cx[i__3].i * 0.5f;
    } else {
        cy[i__2].r = cx[i__2].r;
        cy[i__2].i = cx[i__2].i;
    }
}
}
