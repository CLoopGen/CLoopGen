#include <stdio.h>

#include <inttypes.h>

extern int *PredPel;
extern int i;
extern int LoopArray[25];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to process two elements per iteration
    for (i = 0; i < 25; i += 2) {
        if (i < 25) PredPel[i] = LoopArray[i];
        if (i + 1 < 25) PredPel[i + 1] = LoopArray[i + 1];
    }
}
