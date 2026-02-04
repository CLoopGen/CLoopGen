#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[3];
    for (i = 0; i < 3; ++i) {
        temp[i] = i * 2;
    }
    // Eliminates loop-carried dependencies: each iteration writes to a unique memory location.
    // No data dependence between iterations (no RAW, WAR, WAW across iterations), enabling full parallelization.
}
