#include <stdio.h>

#include <inttypes.h>

extern int FirstMBInSlice[8];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int factor = 3;
    for (k = 0; k < 24; k++) {
        int index = k / 3;
        if (index < 8)
            FirstMBInSlice[index] = (index * factor) - (factor + 7);
    }
}
