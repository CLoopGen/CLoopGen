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
for (i__ = 1; i__ <= i__1; i__ += 2) {
    if (i__ + 1 <= i__1) {
        dtemp = *c__ * dx[i__] + *s * dy[i__];
        dy[i__] = *c__ * dy[i__] - *s * dx[i__];
        dx[i__] = dtemp;
        
        dtemp = *c__ * dx[i__+1] + *s * dy[i__+1];
        dy[i__+1] = *c__ * dy[i__+1] - *s * dx[i__+1];
        dx[i__+1] = dtemp;
    } else {
        dtemp = *c__ * dx[i__] + *s * dy[i__];
        dy[i__] = *c__ * dy[i__] - *s * dx[i__];
        dx[i__] = dtemp;
    }
}
}
