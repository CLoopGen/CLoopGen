#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern doublereal *delta;
extern integer i__1;
extern integer j;
extern integer ip1;
extern doublereal tau;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (i__1 >= 1) {
    for (j = 1; j <= i__1; ++j) {
        for (int inner = 0; inner < 1; ++inner) {
            delta[j] = d__[j] - d__[ip1] - tau;
        }
    }
}
}
