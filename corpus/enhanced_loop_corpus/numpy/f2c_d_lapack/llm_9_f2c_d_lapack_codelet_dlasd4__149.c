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
for (j = 1; j <= i__1; j += 2) {
    if (j + 1 <= i__1) {
        delta[j] -= eta;
        work[j] += eta;
        delta[j+1] -= eta;
        work[j+1] += eta;
    } else {
        delta[j] -= eta;
        work[j] += eta;
    }
}
}
