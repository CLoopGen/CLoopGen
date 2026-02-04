#include <stdio.h>

#include <inttypes.h>

extern int *PredPel;
extern int i;
extern int LoopArray[25];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing consecutive elements, access every second element (stride of 2)
    // Adjust bounds accordingly to stay within valid range
    for (i = 4; i < 16; i += 2) {
        LoopArray[i] = ((&(PredPel[0]))[i - 2] + ((&(PredPel[0]))[i] << 1) + (&(PredPel[0]))[i + 2] + 2) >> 2;
    }
    // Handle remaining even indices if needed, but loop bounds kept realistic
}
