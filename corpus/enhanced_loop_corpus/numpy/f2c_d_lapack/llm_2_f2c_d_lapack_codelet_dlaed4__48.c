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
    // Variant 1: Strided memory access (access every 2nd element in reverse order)
    for (j = i__1; j >= 1; j -= 2) {
        delta[j] -= eta;
    }
    // Handle odd-sized range by adjusting start if needed, but logic remains valid as is
}
