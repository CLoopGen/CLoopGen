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
    for (i__ = mp1; i__ <= i__2; i__ += 5) {
        doublereal temp = *da;
        if (temp > 0.0) {
            dx[i__] *= temp;
            dx[i__ + 2] *= temp;
            dx[i__ + 4] *= temp;
        }
        if (temp <= 0.0) {
            dx[i__ + 1] = -dx[i__ + 1]; 
            dx[i__ + 3] = -dx[i__ + 3];
        }
    }
}
