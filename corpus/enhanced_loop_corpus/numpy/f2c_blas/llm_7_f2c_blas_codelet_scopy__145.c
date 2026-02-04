#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *sx;
extern real *sy;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 1; i__ <= i__1; ++i__) {
        sy[i__] = sx[i__];
        sy[i__ - 1] = sx[i__]; // Introduces WAW and WAR dependency; creates loop-carried dependence due to write at previous index
    }
    sy[i__1] = sx[i__1]; // Fix last element if needed, though main loop already handles it
}
