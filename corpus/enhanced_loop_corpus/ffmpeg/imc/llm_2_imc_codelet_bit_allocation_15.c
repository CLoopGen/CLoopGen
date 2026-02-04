#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern float highest;
extern float workT[32];
extern int found_indx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to process two elements per iteration
    highest = -__FLT_MAX__;
    found_indx = -1;
    int limit = 32;
    for (i = 0; i < limit; i += 2) {
        int idx1 = i;
        int idx2 = i + 1;
        if (idx1 < limit && workT[idx1] > highest) {
            highest = workT[idx1];
            found_indx = idx1;
        }
        if (idx2 < limit && workT[idx2] > highest) {
            highest = workT[idx2];
            found_indx = idx2;
        }
    }
}
