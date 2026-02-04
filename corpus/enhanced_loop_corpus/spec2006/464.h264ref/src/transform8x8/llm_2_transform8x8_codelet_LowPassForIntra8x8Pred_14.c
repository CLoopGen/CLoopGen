#include <stdio.h>

#include <inttypes.h>

extern int *PredPel;
extern int i;
extern int LoopArray[25];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, unrolled by factor 2)
    for (i = 0; i < 25; i += 2) {
        LoopArray[i] = PredPel[i];
        if (i + 1 < 25)
            LoopArray[i + 1] = PredPel[i + 1];
    }
}
