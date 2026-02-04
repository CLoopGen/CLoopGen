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
    i__2 = i__;
    z__2.r = *c__ * cx[i__2].r , z__2.i = *c__ * cx[i__2].i;
    i__3 = i__;
    z__3.r = *s * cy[i__3].r , z__3.i = *s * cy[i__3].i;
    z__1.r = z__2.r + z__3.r , z__1.i = z__2.i + z__3.i;
    ctemp.r = z__1.r , ctemp.i = z__1.i;
    i__2 = i__;
    i__3 = i__;
    z__2.r = *c__ * cy[i__3].r , z__2.i = *c__ * cy[i__3].i;
    i__4 = i__;
    z__3.r = *s * cx[i__4].r , z__3.i = *s * cx[i__4].i;
    z__1.r = z__2.r - z__3.r , z__1.i = z__2.i - z__3.i;
    cy[i__2].r = z__1.r , cy[i__2].i = z__1.i;
    i__2 = i__;
    cx[i__2].r = ctemp.r , cx[i__2].i = ctemp.i;
}

}
