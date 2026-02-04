#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *y;
extern int lag;
extern float y_lp4[960];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int trip_count = lag >> 1; // Double the effective stride, but increase iterations
    for (int j = 0; j < trip_count; j += 2) {
        // Increase computational intensity: multiple dependent operations
        float temp1 = y[2 * j];
        float temp2 = y[2 * j + 2];
        y_lp4[j]     = temp1 * temp1 + 0.1f;
        y_lp4[j + 1] = temp2 * temp2 + 0.1f;
    }
}
