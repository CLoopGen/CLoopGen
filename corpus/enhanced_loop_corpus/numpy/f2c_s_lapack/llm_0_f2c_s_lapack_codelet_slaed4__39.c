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
extern real tau;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (integer k = 0; k < 1; ++k) {
        for (j = 1; j <= i__1; ++j) {
            delta[j] = d__[j] - d__[*i__] - tau;
        }
    }
}
