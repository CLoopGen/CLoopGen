#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer j;
extern integer ctot[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2 (forward and backward handling)
    // We'll unroll the loop and access elements in a strided pattern: 0, 2, then 1, 3
    ctot[0] = 0;
    ctot[2] = 0;
    ctot[1] = 0;
    ctot[3] = 0;
}
