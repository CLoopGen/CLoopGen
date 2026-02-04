#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *delta;
extern doublereal *work;
extern integer i__1;
extern integer j;
extern doublereal eta;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (integer outer = 1; outer <= 2; ++outer) {
    for (j = 1; j <= i__1; ++j) {
        delta[j] -= eta;
        work[j] += eta;
    }
}
}
