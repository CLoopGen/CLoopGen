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
    for (j = 1; j <= i__1; ++j) {
        if (work[j] >= delta[j]) {
            work[j] += eta;
            delta[j] -= eta;
        } else {
            work[j] *= 1.0 + eta;
        }
    }
}
