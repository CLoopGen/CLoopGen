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
extern real temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real prev_work = 0.0f;
    for (j = 1; j <= i__1; ++j) {
        real current_d = d__[j];
        work[j] = current_d + d__[*i__] + temp + prev_work;
        delta[j] = current_d - d__[*i__] - temp;
        prev_work = work[j];
    }
}
