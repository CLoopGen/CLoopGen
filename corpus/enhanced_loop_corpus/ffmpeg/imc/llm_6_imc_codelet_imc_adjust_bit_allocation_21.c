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
    int temp_found_indx = found_indx;
    for (i = 0; i < 32; i++) {
        float val = workT[i];
        if (val > temp_highest) {
            temp_highest = val;
            temp_found_indx = i;
        }
    }
    highest = temp_highest;
    found_indx = temp_found_indx;
}
