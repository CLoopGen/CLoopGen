#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *bounding_values;
extern int16_t temp_16[8];
extern int temp_32[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 8; i += 2) {
        int idx1 = temp_16[i];
        int idx2 = temp_16[i + 1];
        temp_32[i] = bounding_values[idx1] + idx1 - idx2;
        temp_32[i + 1] = bounding_values[idx2] + idx2 - idx1;
    }
}
