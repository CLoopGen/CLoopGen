#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *i__;
extern real *d__;
extern real *delta;
extern real *work;
extern integer i__1;
extern integer j;
extern real eta;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= i__1; ++j) {
        work[j] = d__[j] + d__[*i__] + eta;
        delta[j] = d__[j] - d__[*i__] - eta;
        if (j < i__1) {
            work[j+1] = d__[j+1] + d__[*i__] + eta;
            delta[j+1] = d__[j+1] - d__[*i__] - eta;
        }
    }
}
