#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *bounding_values;
extern int16_t temp_16[8];
extern int temp_32[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_index = 0;
    for (int i = 0; i < 8; i++) {
        int curr_index = temp_16[i] + prev_index;
        temp_32[i] = bounding_values[curr_index & 7];
        prev_index = curr_index;
    }
}
