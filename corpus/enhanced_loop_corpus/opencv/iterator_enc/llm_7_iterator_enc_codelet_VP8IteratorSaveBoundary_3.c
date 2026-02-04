#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[16];
    for (i = 0; i < 16; ++i) {
        arr[i] = i * 2;
    }
    // Introduces array element WAW dependencies (each write to distinct arr[i] is independent).
    // Eliminates loop-carried dependencies: each iteration writes to a unique memory location.
    // Demonstrates parallelizable loop with no inter-iteration data dependence.
}
