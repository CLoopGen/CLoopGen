#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *image;
extern int height;
extern int width;
extern int top;
extern int left;
extern int height_new;
extern int width_new;
extern int i;
extern int j;
extern float *result;
extern float temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int total_elements = height_new * width_new;
for (i = 0; i < total_elements; i++) {
    int row = i / width_new;
    int col = i % width_new;
    int src_idx = (height - 1 - (row + top)) * width + (col + left);
    temp = (float)image[src_idx];
    result[i] = (temp < 0) ? temp + 256.0f : temp;
}
}
