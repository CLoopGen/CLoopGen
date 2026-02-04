#include <stdio.h>

#include <inttypes.h>

extern int FirstMBInSlice[8];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < 8; k++) {
        if (k % 2 == 0) {
            FirstMBInSlice[k] = -1;
        } else {
            continue;
        }
    }
}
