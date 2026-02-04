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
int idx = 0;
for (i = 0; i < width_new * height_new; i++) {
    int col = i / height_new;
    int row = i % height_new;
    result_converted[i] = result[row * width_new + col];
}
}
