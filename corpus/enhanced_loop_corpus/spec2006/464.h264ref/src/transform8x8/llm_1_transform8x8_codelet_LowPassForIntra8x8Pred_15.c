#include <stdio.h>

#include <inttypes.h>

extern int *PredPel;
extern int i;
extern int LoopArray[25];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            PredPel[i * 5 + j] = LoopArray[i * 5 + j];
}
