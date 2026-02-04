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
    real temp1, temp2, temp3, temp4, temp5;
    for (i__ = mp1; i__ <= i__2 - 4; i__ += 5) {
        temp1 = *sa * sx[i__];
        temp2 = *sa * sx[i__ + 1];
        temp3 = *sa * sx[i__ + 2];
        temp4 = *sa * sx[i__ + 3];
        temp5 = *sa * sx[i__ + 4];
        sx[i__] = temp1;
        sx[i__ + 1] = temp2;
        sx[i__ + 2] = temp3;
        sx[i__ + 3] = temp4;
        sx[i__ + 4] = temp5;
    }
    // Handle any remaining elements if the range isn't a multiple of 5
    for (; i__ <= i__2; ++i__) {
        sx[i__] = *sa * sx[i__];
    }
}
