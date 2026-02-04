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
for (i__ = 1; i__ <= i__1; ++i__) {
    singlecomplex temp_cx = cx[i__];
    singlecomplex temp_cy = cy[i__];
    
    // Introduce local reuse: compute intermediate values with modified dependency order
    real c_cx_r = *c__ * temp_cx.r;
    real c_cx_i = *c__ * temp_cx.i;
    real s_cy_r = *s * temp_cy.r;
    real s_cy_i = *s * temp_cy.i;
    
    // Combine earlier to create WAW and WAR dependencies explicitly via temp storage
    ctemp.r = c_cx_r + s_cy_r;
    ctemp.i = c_cx_i + s_cy_i;
    
    real c_cy_r = *c__ * temp_cy.r;
    real c_cy_i = *c__ * temp_cy.i;
    real s_cx_r = *s * temp_cx.r;
    real s_cx_i = *s * temp_cx.i;
    
    // Modify write order: write to cy before updating cx, removing potential race in pipelined execution
    cy[i__].r = c_cy_r - s_cx_r;
    cy[i__].i = c_cy_i - s_cx_i;
    
    cx[i__].r = ctemp.r;
    cx[i__].i = ctemp.i;
}
}
