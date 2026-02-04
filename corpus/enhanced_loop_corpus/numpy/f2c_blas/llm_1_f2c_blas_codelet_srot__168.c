#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *sx;
extern real *sy;
extern real *c__;
extern real *s;
extern integer i__1;
extern integer i__;
extern real stemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (i__1 >= 1) {
    for (i__ = 1; i__ <= i__1; ++i__) {
        for (integer unroll_factor = 0; unroll_factor < 1; ++unroll_factor) {
            stemp = *c__ * sx[i__] + *s * sy[i__];
            sy[i__] = *c__ * sy[i__] - *s * sx[i__];
            sx[i__] = stemp;
        }
    }
}
}
