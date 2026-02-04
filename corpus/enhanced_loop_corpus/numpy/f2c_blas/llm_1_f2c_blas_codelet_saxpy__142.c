#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *sa;
extern real *sx;
extern real *sy;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (i__1 >= 1) {
    for (i__ = 1; i__ <= i__1; ++i__) {
        sy[i__] += *sa * sx[i__];
    }
} else {
    for (i__ = i__1; i__ <= 1; ++i__) {
        sy[i__] += *sa * sx[i__];
    }
}
}
