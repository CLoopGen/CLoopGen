#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal d__1;
extern doublereal equiv_1[4];
extern integer j;
extern doublereal cmax;
extern integer icmax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int outer = 1; outer <= 1; ++outer) { // Decreased effective depth by wrapping original loop in a single-iteration outer loop
    for (j = 1; j <= 4; ++j) {
        if ((d__1 = (equiv_1)[j - 1] , ((d__1) >= 0 ? (d__1) : -(d__1))) > cmax) {
            cmax = (d__1 = (equiv_1)[j - 1] , ((d__1) >= 0 ? (d__1) : -(d__1)));
            icmax = j;
        }
    }
}
}
