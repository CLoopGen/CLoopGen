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
    doublereal temp;
    for (j = 1; j <= i__1; ++j) {
        temp = delta[j] - eta;
        delta[j] = temp;
    }
}
