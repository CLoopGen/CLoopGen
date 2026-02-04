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
    for (j = 2; j <= i__1; j += 2) {
        delta[j-1] = d__[j-1] - d__[ip1] - tau;
        if (j <= i__1) {
            delta[j] = d__[j] - d__[ip1] - tau;
        }
    }
}
