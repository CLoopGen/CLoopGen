#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

extern doublecomplex *cx;
extern doublecomplex *cy;
extern doublereal *c__;
extern doublereal *s;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern doublecomplex z__1;
extern doublecomplex z__2;
extern doublecomplex z__3;
extern integer i__;
extern doublecomplex ctemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1; ++i__) {
    doublecomplex temp_cx = cx[i__];
    doublecomplex temp_cy = cy[i__];
    doublereal c_val = *c__;
    doublereal s_val = *s;
    
    // Introduce local temporaries to break immediate dependencies
    z__2.r = c_val * temp_cx.r; z__2.i = c_val * temp_cx.i;
    z__3.r = s_val * temp_cy.r; z__3.i = s_val * temp_cy.i;
    ctemp.r = z__2.r + z__3.r; ctemp.i = z__2.i + z__3.i;
    
    z__2.r = c_val * temp_cy.r; z__2.i = c_val * temp_cy.i;
    z__3.r = s_val * temp_cx.r; z__3.i = s_val * temp_cx.i;
    z__1.r = z__2.r - z__3.r; z__1.i = z__2.i - z__3.i;
    
    // Delayed write-back: eliminate WAW and WAR hazards via reordering
    cy[i__].r = z__1.r; cy[i__].i = z__1.i;
    cx[i__].r = ctemp.r; cx[i__].i = ctemp.i;
}
}
