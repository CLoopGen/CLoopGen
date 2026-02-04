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
    // Variant 1: Strided memory access (access every 2nd element first, then fill gaps)
    // This modifies the access pattern to be non-consecutive with a stride of 2
    integer stride = 2;
    integer start;

    for (start = 0; start < stride; ++start) {
        for (j = start + 1; j <= i__1; j += stride) {
            indx[j] = j;
        }
    }
}
