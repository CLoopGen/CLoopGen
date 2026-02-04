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
    sx[i__] = *sa * sx[i__];
    sx[i__ + 1] = *sa * sx[i__ + 1];
    sx[i__ + 2] = *sa * sx[i__ + 2];
    sx[i__ + 3] = *sa * sx[i__ + 3];
    sx[i__ + 4] = *sa * sx[i__ + 4];
}

}
