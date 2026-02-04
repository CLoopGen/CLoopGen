#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_copy[4];
    for (i = 0; i < 4; i++) {
        local_copy[i] = i * 2;
    }
    // Removes loop-carried dependencies by making each iteration write to independent array elements
    // Introduces no inter-iteration data dependencies (RAW, WAR, WAW are eliminated across iterations)
    // Enables potential for full loop parallelization.
}
