#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern float lowest;
extern int low_indx;
extern float workT[32];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2), iterating only over even indices
    for (i = 0; i < 32; i += 2) {
        if (workT[i] < lowest) {
            lowest = workT[i];
            low_indx = i;
        }
    }
    // Complete the odd indices in a second pass to maintain full array coverage
    for (i = 1; i < 32; i += 2) {
        if (workT[i] < lowest) {
            lowest = workT[i];
            low_indx = i;
        }
    }
}
