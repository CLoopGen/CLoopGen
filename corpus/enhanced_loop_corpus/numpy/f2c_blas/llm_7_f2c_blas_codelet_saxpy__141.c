#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *sa;
extern real *sx;
extern integer *incx;
extern real *sy;
extern integer *incy;
extern integer i__1;
extern integer i__;
extern integer ix;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real local_sy;
    for (i__ = 1; i__ <= i__1; ++i__) {
        local_sy = sy[iy];          // Load once
        sy[iy] = local_sy + *sa * sx[ix]; // Remove potential RAW hazard by using local copy (though not carried)
        ix += *incx;
        iy += *incy;
    }
}
