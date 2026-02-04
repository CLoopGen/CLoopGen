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
extern integer mp1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real temp1, temp2, temp3, temp4;
    for (i__ = mp1; i__ <= i__1; i__ += 4) {
        temp1 = *sa * sx[i__];
        temp2 = *sa * sx[i__ + 1];
        temp3 = *sa * sx[i__ + 2];
        temp4 = *sa * sx[i__ + 3];
        sy[i__] += temp1;
        sy[i__ + 1] += temp2;
        sy[i__ + 2] += temp3;
        sy[i__ + 3] += temp4;
    }
}
