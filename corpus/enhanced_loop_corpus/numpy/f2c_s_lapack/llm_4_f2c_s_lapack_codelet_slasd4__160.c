#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *d__;
extern real *delta;
extern real *work;
extern integer i__1;
extern integer j;
extern integer ip1;
extern real eta;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= i__1; ++j) {
        if (d__[j] >= 0.0) {
            work[j] = d__[j] + d__[ip1] + eta;
            delta[j] = d__[j] - d__[ip1] - eta;
        } else {
            work[j] = 0.0;
            delta[j] = 0.0;
        }
    }
}
