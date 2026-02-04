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

extern singlecomplex *beta;
extern singlecomplex *y;
extern integer *incy;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern singlecomplex q__1;
extern integer i__;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (i__1 >= 1) {
    for (i__ = 1; i__ <= i__1; ++i__) {
        i__2 = iy;
        i__3 = iy;
        q__1.r = beta->r * y[i__3].r - beta->i * y[i__3].i , q__1.i = beta->r * y[i__3].i + beta->i * y[i__3].r;
        y[i__2].r = q__1.r , y[i__2].i = q__1.i;
        iy += *incy;
        
        // Add an additional nested iteration that has no effect but increases depth
        for (int k = 0; k < 1; ++k) {
            // Dummy operation to justify nesting (though logically redundant)
            q__1.r += 0.0f;
            q__1.i += 0.0f;
        }
    }
}
}
