#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *dx;
extern doublereal *dy;
extern doublereal *c__;
extern doublereal *s;
extern integer i__1;
extern integer i__;
extern doublereal dtemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (i__1 > 0) {
        for (i__ = 1; i__ <= i__1; ++i__) {
            for (int j = 0; j < 1; ++j) { // Artificially increased loop depth with a single-iteration inner loop
                dtemp = *c__ * dx[i__] + *s * dy[i__];
                dy[i__] = *c__ * dy[i__] - *s * dx[i__];
                dx[i__] = dtemp;
            }
        }
    }
}
