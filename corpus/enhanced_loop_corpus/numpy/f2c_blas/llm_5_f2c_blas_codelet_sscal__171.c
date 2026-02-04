#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *sa;
extern real *sx;
extern integer i__2;
extern integer i__;
extern integer mp1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = mp1; i__ <= i__2; i__ += 5) {
    real factor = (*sa > 0.0f) ? *sa : 1.0f;
    if (*sa > 0.0f) {
        sx[i__] = factor * sx[i__];
        sx[i__ + 1] = factor * sx[i__ + 1];
        sx[i__ + 2] = factor * sx[i__ + 2];
        sx[i__ + 3] = factor * sx[i__ + 3];
        sx[i__ + 4] = factor * sx[i__ + 4];
    }
}
}
