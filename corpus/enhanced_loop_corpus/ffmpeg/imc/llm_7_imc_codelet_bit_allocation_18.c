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
    float temp_array[32];
    int indices[32];
    for (i = 0; i < 32; i++) {
        temp_array[i] = workT[i];
        indices[i] = i;
    }
    for (i = 1; i < 32; i++) {
        if (temp_array[i] < temp_array[i - 1]) {
            temp_array[i] = temp_array[i];
            indices[i] = indices[i];
        } else {
            temp_array[i] = temp_array[i - 1];
            indices[i] = indices[i - 1];
        }
    }
    lowest = temp_array[31];
    low_indx = indices[31];
}
