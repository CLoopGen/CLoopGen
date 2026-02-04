#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern float highest;
extern float workT[32];
extern int found_indx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float local_highest = workT[0];
    int local_indx = 0;
    for (i = 1; i < 32; i++) {
        float prev_highest = local_highest;
        int prev_indx = local_indx;
        if (workT[i] > prev_highest) {
            local_highest = workT[i];
            local_indx = i;
        } else {
            local_highest = prev_highest;
            local_indx = prev_indx;
        }
    }
    highest = local_highest;
    found_indx = local_indx;
}
