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
    doublereal prev = 0.0;
    for (j = 1; j <= i__1; ++j) {
        doublereal current = delta[j];
        delta[j] = current - eta - prev;
        prev = current;
    }
}
