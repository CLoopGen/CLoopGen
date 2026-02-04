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
    // Variant 2: Reverse consecutive memory access with indirect assignment via pointer arithmetic
    integer *base = indx;
    for (j = i__1; j >= 1; --j) {
        *(base + j) = j;
    }
}
