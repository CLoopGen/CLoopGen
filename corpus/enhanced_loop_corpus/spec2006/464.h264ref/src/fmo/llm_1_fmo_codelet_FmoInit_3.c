#include <stdio.h>

#include <inttypes.h>

extern int FirstMBInSlice[8];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < 4; k++) {
        FirstMBInSlice[k] = -1;
        FirstMBInSlice[k + 4] = -1;
    }
}
