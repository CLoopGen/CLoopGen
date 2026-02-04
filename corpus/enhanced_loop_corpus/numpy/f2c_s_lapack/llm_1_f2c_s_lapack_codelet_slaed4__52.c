#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *d__;
extern real *delta;
extern integer i__1;
extern integer j;
extern integer ip1;
extern real tau;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (i__1 >= 1) {
    for (j = 1; j <= i__1; ++j) {
        for (integer inner = 0; inner < 1; ++inner) {
            delta[j] = d__[j] - d__[ip1] - tau;
        }
    }
}
}
