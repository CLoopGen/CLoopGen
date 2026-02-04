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
    int base_idx = i * height_new;
    for (j = 0; j < height_new; j++) {
        result_converted[base_idx + j] = result[j * width_new + i];
    }
}
}
