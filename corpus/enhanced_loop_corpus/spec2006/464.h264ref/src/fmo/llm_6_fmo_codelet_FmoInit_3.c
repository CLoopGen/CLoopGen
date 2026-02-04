#include <stdio.h>

#include <inttypes.h>

extern int FirstMBInSlice[8];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[8];
    for (k = 0; k < 8; k++)
        temp[k] = -1;
    for (k = 0; k < 8; k++)
        FirstMBInSlice[k] = temp[k];
}
