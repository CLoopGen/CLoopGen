#include <stdio.h>

#include <inttypes.h>

extern int *PredPel;
extern int i;
extern int LoopArray[25];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (accessing every other element)
    // Adjust loop bounds to ensure we don't go out of bounds when using stride
    for (i = 18; i < 24; i += 2) {
        LoopArray[i] = ((&(PredPel[0]))[i - 1] + ((&(PredPel[0]))[i] << 1) + (&(PredPel[0]))[i + 1] + 2) >> 2;
        if (i + 1 < 24) {
            LoopArray[i + 1] = ((&(PredPel[0]))[i] + ((&(PredPel[0]))[i + 1] << 1) + (&(PredPel[0]))[i + 2] + 2) >> 2;
        }
    }
}
