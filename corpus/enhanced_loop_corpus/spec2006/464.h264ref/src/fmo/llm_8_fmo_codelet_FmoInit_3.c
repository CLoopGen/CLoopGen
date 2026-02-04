#include <stdio.h>

#include <inttypes.h>

extern int FirstMBInSlice[8];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < 8; k += 2) {
        FirstMBInSlice[k] = -1;
        if (k + 1 < 8)
            FirstMBInSlice[k + 1] = -1;
    }
}
