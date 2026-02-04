#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *indx;
extern integer i__1;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element first, then odd indices)
    // This changes the access pattern from sequential to strided with stride 2
    integer stride = 2;
    for (j = 1; j <= i__1; j += stride) {
        indx[j] = j;
    }
    for (j = 2; j <= i__1; j += stride) {
        indx[j] = j;
    }
}
