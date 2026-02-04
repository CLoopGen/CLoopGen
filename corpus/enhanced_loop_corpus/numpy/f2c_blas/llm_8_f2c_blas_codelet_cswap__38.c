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
extern singlecomplex ctemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1; ++i__) {
    i__2 = i__;
    ctemp.r = cx[i__2].r + 0.5f, ctemp.i = cx[i__2].i - 0.3f;
    i__2 = i__;
    i__3 = i__;
    cx[i__2].r = cy[i__3].r * 1.2f, cx[i__2].i = cy[i__3].i * 1.2f;
    i__2 = i__;
    cy[i__2].r = ctemp.r * 0.8f, cy[i__2].i = ctemp.i * 0.8f;
}
}
