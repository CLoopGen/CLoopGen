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
    ptrdiff_t idx = (i__ * 7) % (i__1 + 1);
    if (idx == 0) idx = i__1;
    i__2 = idx;
    ctemp.r = cx[i__2].r , ctemp.i = cx[i__2].i;
    i__2 = idx;
    i__3 = idx;
    cx[i__2].r = cy[i__3].r , cx[i__2].i = cy[i__3].i;
    i__2 = idx;
    cy[i__2].r = ctemp.r , cy[i__2].i = ctemp.i;
}
}
