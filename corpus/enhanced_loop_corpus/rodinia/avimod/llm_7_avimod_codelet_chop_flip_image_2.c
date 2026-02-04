#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height_new;
extern int width_new;
extern int i;
extern int j;
extern float *result;
extern float *result_converted;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < width_new; i++) {
        for (j = 1; j < height_new; j++) {
            result_converted[i * height_new + j] = result_converted[i * height_new + j - 1] + result[(j - 1) * width_new + i];
        }
        if (height_new > 0) {
            result_converted[i * height_new] = result[i];
        }
    }
}
