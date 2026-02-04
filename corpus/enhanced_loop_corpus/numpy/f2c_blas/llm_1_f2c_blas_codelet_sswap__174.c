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
    for (i__ = mp1; i__ <= i__1; i__ += 9) { // Increase step and add inner loop to maintain access pattern
        for (integer offset = 0; offset < 3 && (i__ + offset * 3) <= i__1; ++offset) {
            integer idx = i__ + offset * 3;
            stemp = sx[idx];
            sx[idx] = sy[idx];
            sy[idx] = stemp;
            if (idx + 1 <= i__1) {
                stemp = sx[idx + 1];
                sx[idx + 1] = sy[idx + 1];
                sy[idx + 1] = stemp;
            }
            if (idx + 2 <= i__1) {
                stemp = sx[idx + 2];
                sx[idx + 2] = sy[idx + 2];
                sy[idx + 2] = stemp;
            }
        }
    }
}
