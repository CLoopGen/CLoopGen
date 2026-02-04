#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *y;
extern int lag;
extern float y_lp4[960];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int trip_count = lag >> 3; // Reduce trip count by half compared to original
    for (int j = 0; j < trip_count; j++) {
        y_lp4[2*j]     = y[4 * j];
        y_lp4[2*j + 1] = y[4 * j + 2];
    }
}
