#include <stdio.h>

#include <inttypes.h>

extern int *PredPel;
extern int i;
extern int LoopArray[25];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 4; i < 12; i += 2) {
    int temp1 = ((&(PredPel[0]))[i - 2] + ((&(PredPel[0]))[i] << 1) + (&(PredPel[0]))[i + 2]);
    int temp2 = ((&(PredPel[0]))[i - 1] + ((&(PredPel[0]))[i] << 1) + (&(PredPel[0]))[i + 1]);
    LoopArray[i] = (temp1 + 2) >> 2;
    LoopArray[i - 1] = (temp2 + 2) >> 2;
}
}
