#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int n2;
extern  int n4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Assume an array is accessed with a fixed stride (e.g., every 4th element)
    // Using global index i, stepping through with stride of 4
    for (i = n4; i < n2; i += 4) {
        // Simulated strided access (e.g., arr[i] would be accessed here)
    }
}
