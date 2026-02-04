#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern float lowest;
extern int low_indx;
extern float workT[32];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i++) {
    int idx1 = i;
    int idx2 = i + 16;
    if (workT[idx1] < lowest) {
        lowest = workT[idx1];
        low_indx = idx1;
    }
    if (workT[idx2] < lowest) {
        lowest = workT[idx2];
        low_indx = idx2;
    }
}
}
