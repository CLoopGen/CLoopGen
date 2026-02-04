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
extern integer mp1;
extern real stemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = mp1; i__ <= i__1; i__++) {
        switch ((i__ - mp1) % 5) {
            case 0: stemp += sx[i__] * sy[i__]; break;
            case 1: stemp += sx[i__] * sy[i__]; break;
            case 2: stemp += sx[i__] * sy[i__]; break;
            case 3: stemp += sx[i__] * sy[i__]; break;
            case 4: stemp += sx[i__] * sy[i__]; break;
        }
    }
}
