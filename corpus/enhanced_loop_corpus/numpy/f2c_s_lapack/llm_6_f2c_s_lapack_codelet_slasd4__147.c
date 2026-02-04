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
    real temp_delta;
    real temp_work;
    for (j = 1; j <= i__1; ++j) {
        temp_delta = d__[j] - d__[*i__] - eta;
        temp_work = d__[j] + d__[*i__] + eta;
        delta[j] = temp_delta;
        work[j] = temp_work;
    }
}
