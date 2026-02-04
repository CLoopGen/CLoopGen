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
integer skip_first = (mp1 % 2) == 0 ? 0 : 4;
for (i__ = mp1 + skip_first; i__ <= i__1; i__ += 8) {
    sy[i__] += *sa * sx[i__];
    sy[i__ + 1] += *sa * sx[i__ + 1];
    sy[i__ + 2] += *sa * sx[i__ + 2];
    sy[i__ + 3] += *sa * sx[i__ + 3];
}
}
