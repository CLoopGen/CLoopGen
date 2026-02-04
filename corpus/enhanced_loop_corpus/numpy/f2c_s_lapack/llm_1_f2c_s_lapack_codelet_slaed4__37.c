#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *i__;
extern real *d__;
extern real *delta;
extern integer i__1;
extern integer j;
extern real midpt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (i__1 >= 1) {
    for (j = 1; j <= i__1; ++j) {
        for (integer step = 1; step <= 1; ++step) {
            delta[j] = d__[j] - d__[*i__] - midpt;
        }
    }
}
}
