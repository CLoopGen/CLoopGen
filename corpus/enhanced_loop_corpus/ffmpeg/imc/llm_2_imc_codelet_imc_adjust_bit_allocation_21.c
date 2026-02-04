#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float workT[32];
extern int i;
extern float highest;
extern int found_indx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < 32; i += 2) {
        if (workT[i] > highest) {
            highest = workT[i];
            found_indx = i;
        }
    }
    // Handle odd indices in a second pass to ensure all elements are considered
    for (i = 1; i < 32; i += 2) {
        if (workT[i] > highest) {
            highest = workT[i];
            found_indx = i;
        }
    }
}
