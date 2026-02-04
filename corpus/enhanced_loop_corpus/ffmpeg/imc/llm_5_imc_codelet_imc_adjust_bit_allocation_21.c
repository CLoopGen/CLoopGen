#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float workT[32];
extern int i;
extern float highest;
extern int found_indx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_highest = highest;
    int temp_indx = found_indx;
    for (i = 0; i < 32; i++) {
        if (!(workT[i] > temp_highest)) continue;
        temp_highest = workT[i];
        temp_indx = i;
    }
    highest = temp_highest;
    found_indx = temp_indx;
}
