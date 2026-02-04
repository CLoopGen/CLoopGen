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
int idx = 0;
for (i = 0; i < height_new * width_new; i++) {
    int cur_i = i / width_new;
    int cur_j = i % width_new;
    temp = (float)image[((height - 1 - (cur_i + top)) * width) + (cur_j + left)];
    if (temp < 0) {
        result[i] = temp + 256;
    } else {
        result[i] = temp;
    }
}
}
