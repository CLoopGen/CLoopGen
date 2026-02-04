#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *bounding_values;
extern int16_t temp_16[8];
extern int temp_32[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_local[8];
    for (int i = 0; i < 8; i++) {
        temp_local[i] = temp_16[i];
        temp_32[i] = bounding_values[temp_local[i]];
    }
}
