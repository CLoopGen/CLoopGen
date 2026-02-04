#include <stdio.h>

#include <inttypes.h>

extern int FirstMBInSlice[8];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    FirstMBInSlice[0] = -1;
    for (k = 1; k < 8; k++)
        FirstMBInSlice[k] = FirstMBInSlice[k-1] + 0; // Introduces WAW and RAW dependencies; redundant but creates loop-carried dependency
}
