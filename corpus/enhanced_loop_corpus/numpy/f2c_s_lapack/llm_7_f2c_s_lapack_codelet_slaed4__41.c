#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *delta;
extern integer i__1;
extern integer j;
extern real eta;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real acc = 0.0;
    for (j = 1; j <= i__1; ++j) {
        acc += delta[j];
    }
    for (j = 1; j <= i__1; ++j) {
        delta[j] = delta[j] - eta;
    }
}
