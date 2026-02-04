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
// Introduce loop-carried dependency by making each iteration depend on previous ctemp
ctemp.r = 0.0f;
ctemp.i = 0.0f;
for (i__ = 1; i__ <= i__1; ++i__) {
    singlecomplex prev_ctemp = ctemp; // Create loop-carried dependence (RAW/WAW)
    
    i__2 = i__;
    q__2.r = *c__ * cx[i__2].r + prev_ctemp.r;
    q__2.i = *c__ * cx[i__2].i + prev_ctemp.i;
    
    i__3 = i__;
    q__3.r = *s * cy[i__3].r;
    q__3.i = *s * cy[i__3].i;
    
    q__1.r = q__2.r + q__3.r;
    q__1.i = q__2.i + q__3.i;
    
    ctemp.r = q__1.r;
    ctemp.i = q__1.i;
    
    i__2 = i__;
    i__4 = i__;
    q__2.r = *c__ * cy[i__4].r;
    q__2.i = *c__ * cy[i__4].i;
    
    q__3.r = *s * cx[i__2].r;
    q__3.i = *s * cx[i__2].i;
    
    q__1.r = q__2.r - q__3.r;
    q__1.i = q__2.i - q__3.i;
    
    // Update cy and cx with delayed effect due to ctemp carry
    cy[i__].r = q__1.r;
    cy[i__].i = q__1.i;
    
    cx[i__].r = ctemp.r;
    cx[i__].i = ctemp.i;
}
}
