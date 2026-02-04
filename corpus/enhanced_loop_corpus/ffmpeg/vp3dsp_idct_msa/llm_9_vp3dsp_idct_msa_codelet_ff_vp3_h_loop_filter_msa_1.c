#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *bounding_values;
extern int16_t temp_16[8];
extern int temp_32[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 16; i += 2) {
        int idx = i >> 1;
        temp_32[idx] = bounding_values[temp_16[idx]] * 2;
    }
}
