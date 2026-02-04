#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *da;
extern doublereal *dx;
extern integer i__2;
extern integer i__;
extern integer mp1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (mp1 <= i__2) {
    for (int stride = 0; stride < 5; ++stride) {
        for (i__ = mp1 + stride; i__ <= i__2; i__ += 5) {
            if ((i__ - mp1) % 5 == stride) {
                dx[i__] = *da * dx[i__];
            }
        }
    }
}
}
