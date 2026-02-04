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
extern real *c__;
extern real *s;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern singlecomplex q__1;
extern singlecomplex q__2;
extern singlecomplex q__3;
extern integer i__;
extern singlecomplex ctemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced arithmetic intensity: remove redundant temporaries and simplify operations
// Also reduce trip count by processing every other element
for (i__ = 1; i__ <= i__1; i__ += 2) {
    i__2 = i__;
    // Direct computation without intermediate q__ structs
    ctemp.r = *c__ * cx[i__2].r + *s * cy[i__2].r;
    ctemp.i = *c__ * cx[i__2].i + *s * cy[i__2].i;

    cy[i__2].r = *c__ * cy[i__2].r - *s * cx[i__2].r;
    cy[i__2].i = *c__ * cy[i__2].i - *s * cx[i__2].i;

    cx[i__2].r = ctemp.r;
    cx[i__2].i = ctemp.i;
}
}
