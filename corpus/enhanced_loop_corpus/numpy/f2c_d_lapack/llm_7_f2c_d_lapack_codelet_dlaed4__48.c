#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *delta;
extern integer i__1;
extern integer j;
extern doublereal eta;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal prev_delta = delta[1];
    for (j = 2; j <= i__1; ++j) {
        doublereal current_delta = delta[j];
        delta[j] = prev_delta - eta;
        prev_delta = current_delta;
    }
}
