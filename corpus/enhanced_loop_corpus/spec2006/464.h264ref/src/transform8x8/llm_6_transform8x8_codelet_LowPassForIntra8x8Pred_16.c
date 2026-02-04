#include <stdio.h>

#include <inttypes.h>

extern int *PredPel;
extern int i;
extern int LoopArray[25];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp;
    for (i = 2; i < 16; i++) {
        temp = ((&(PredPel[0]))[i - 1] + ((&(PredPel[0]))[i] << 1) + (&(PredPel[0]))[i + 1] + 2) >> 2;
        LoopArray[i] = temp;
    }
}
