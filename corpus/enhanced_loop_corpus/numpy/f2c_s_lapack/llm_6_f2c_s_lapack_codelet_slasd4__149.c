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
    real temp_delta, temp_work;
    for (j = 1; j <= i__1; ++j) {
        temp_delta = delta[j] - eta;
        temp_work = work[j] + eta;
        delta[j] = temp_delta;
        work[j] = temp_work;
    }
}
