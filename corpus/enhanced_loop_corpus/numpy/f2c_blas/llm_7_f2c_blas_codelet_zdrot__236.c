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
// Reverse iteration to alter loop-carried dependency direction (if any existed externally)
// This creates a different memory access pattern (reverse sequential), changing locality and dependency exposure
for (i__ = i__1; i__ >= 1; --i__) {
    // Use direct indexing without intermediate index variables to remove index assignment dependencies
    z__2.r = *c__ * cx[i__].r; z__2.i = *c__ * cx[i__].i;
    z__3.r = *s * cy[i__].r; z__3.i = *s * cy[i__].i;
    ctemp.r = z__2.r + z__3.r; ctemp.i = z__2.i + z__3.i;

    z__2.r = *c__ * cy[i__].r; z__2.i = *c__ * cy[i__].i;
    z__3.r = *s * cx[i__].r; z__3.i = *s * cx[i__].i;
    z__1.r = z__2.r - z__3.r; z__1.i = z__2.i - z__3.i;

    // Enforce strict update order: cy updated before cx, but in reverse loop index
    cy[i__].r = z__1.r; cy[i__].i = z__1.i;
    cx[i__].r = ctemp.r; cx[i__].i = ctemp.i;
}
}
