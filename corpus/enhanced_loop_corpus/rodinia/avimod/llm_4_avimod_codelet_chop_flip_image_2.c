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
    for (j = 0; j < height_new; j++) {
        if (i % 2 == 0) {
            result_converted[i * height_new + j] = result[j * width_new + i];
        } else {
            result_converted[i * height_new + j] = 0.0f;
        }
    }
}
}
