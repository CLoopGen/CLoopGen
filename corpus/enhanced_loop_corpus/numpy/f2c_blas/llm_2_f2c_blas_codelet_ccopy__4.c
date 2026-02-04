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
for (i__ = 0; i__ < i__1; i__ += 2) {
    i__2 = i__;
    i__3 = i__;
    cy[i__2].r = cx[i__3].r; cy[i__2].i = cx[i__3].i;
    if (i__ + 1 < i__1) {
        i__2 = i__ + 1;
        i__3 = i__ + 1;
        cy[i__2].r = cx[i__3].r; cy[i__2].i = cx[i__3].i;
    }
}
}
