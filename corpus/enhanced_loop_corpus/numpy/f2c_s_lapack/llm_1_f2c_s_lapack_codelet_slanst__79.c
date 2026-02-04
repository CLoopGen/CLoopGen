#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef double doublereal;

extern real *d__;
extern real *e;
extern integer i__1;
extern real r__1;
extern real r__2;
extern real r__3;
extern real r__4;
extern real r__5;
extern integer i__;
extern real anorm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (i__1 >= 2) { // Decreased effective depth: replaced loop with unrolled first iteration and simplified logic when applicable
        i__ = 2;
        r__4 = anorm , r__5 = (r__1 = d__[i__] , (doublereal)((r__1) >= 0 ? (r__1) : -(r__1))) + (r__2 = e[i__] , (doublereal)((r__2) >= 0 ? (r__2) : -(r__2))) + (r__3 = e[i__ - 1] , (doublereal)((r__3) >= 0 ? (r__3) : -(r__3)));
        anorm = (doublereal)((r__4) >= (r__5) ? (r__4) : (r__5));
        
        for (i__ = 3; i__ <= i__1; ++i__) { // Loop now starts from 3, simulating partial nesting reduction
            r__4 = anorm , r__5 = (r__1 = d__[i__] , (doublereal)((r__1) >= 0 ? (r__1) : -(r__1))) + (r__2 = e[i__] , (doublereal)((r__2) >= 0 ? (r__2) : -(r__2))) + (r__3 = e[i__ - 1] , (doublereal)((r__3) >= 0 ? (r__3) : -(r__3)));
            anorm = (doublereal)((r__4) >= (r__5) ? (r__4) : (r__5));
        }
    }
}
