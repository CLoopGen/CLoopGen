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
    int temp_index = found_indx;
    for (i = 0; i < 16; i++) {
        float val1 = workT[2 * i];
        float val2 = workT[2 * i + 1];
        if (val1 > temp_highest) {
            temp_highest = val1;
            temp_index = 2 * i;
        }
        if (val2 > temp_highest) {
            temp_highest = val2;
            temp_index = 2 * i + 1;
        }
    }
    highest = temp_highest;
    found_indx = temp_index;
}
