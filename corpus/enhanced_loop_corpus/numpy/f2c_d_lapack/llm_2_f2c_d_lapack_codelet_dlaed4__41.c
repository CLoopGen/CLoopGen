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
    // Handle the case where i__1 is even by starting at i__1-1 if needed
    if (i__1 % 2 == 0) {
        for (j = i__1 - 1; j >= 1; j -= 2) {
            delta[j] -= eta;
        }
    }
}
