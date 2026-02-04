#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *x;
extern  float *y;
extern float sum[4];
extern int len;
extern float y_0;
extern float y_1;
extern float y_2;
extern float y_3;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced computational intensity: fewer operations per iteration, higher trip count
    for (j = 0; j < len; j++) {
        float tmp = *x++;
        float y_val = *y++;
        
        // Accumulate only one product per iteration, cycling through sum indices
        sum[j % 4] += tmp * y_val;
        
        // Rotate y values to preserve dependency pattern approximately
        if (j % 4 == 0) {
            y_0 = y_val;
        } else if (j % 4 == 1) {
            y_1 = y_val;
        } else if (j % 4 == 2) {
            y_2 = y_val;
        } else {
            y_3 = y_val;
        }
    }
}
