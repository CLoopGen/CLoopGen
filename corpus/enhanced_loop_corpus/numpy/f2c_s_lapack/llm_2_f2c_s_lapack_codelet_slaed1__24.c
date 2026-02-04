#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *indxq;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (step by 2)
    for (i__ = 1; i__ <= i__1; i__ += 2) {
        indxq[i__] = i__;
    }
    // Handle odd-sized range if needed by processing remaining element
    if (i__ - 1 == i__1) {
        indxq[i__ - 1] = i__ - 1;
    }
}
