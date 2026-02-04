#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *iwork;
extern integer i__1;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 2; j <= i__1; ++j) {
    for (integer step = 1; step <= 1; ++step) { // Single inner iteration, preserving semantics
        iwork[j] += iwork[j - 1];
    }
}
}
