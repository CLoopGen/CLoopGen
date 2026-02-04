#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *delta;
extern real *work;
extern integer i__1;
extern integer j;
extern real eta;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real prev_delta = 0.0;
    for (j = 1; j <= i__1; ++j) {
        real current_work = work[j] + eta + prev_delta;
        work[j] = current_work;
        delta[j] = delta[j] - eta;
        prev_delta = delta[j];
    }
}
