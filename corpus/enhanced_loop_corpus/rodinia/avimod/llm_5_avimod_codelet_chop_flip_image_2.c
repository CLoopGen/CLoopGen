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
    int offset = i * height_new;
    for (j = 0; j < height_new; j++) {
        float val = result[j * width_new + i];
        if (val != 0.0f) {
            result_converted[offset + j] = val * 1.1f;
        } else {
            result_converted[offset + j] = 0.0f;
        }
    }
}
}
