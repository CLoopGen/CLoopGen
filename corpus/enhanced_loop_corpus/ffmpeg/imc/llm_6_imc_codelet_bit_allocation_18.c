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
    float temp_lowest = workT[0];
    int temp_low_indx = 0;
    for (i = 1; i < 32; i++) {
        if (workT[i] < temp_lowest) {
            temp_lowest = workT[i];
            temp_low_indx = i;
        }
    }
    lowest = temp_lowest;
    low_indx = temp_low_indx;
}
