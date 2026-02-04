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
extern float scale;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int idx = 0;
for (i = 0; i < height_new; i++) {
    for (j = 0; j < width_new; j++, idx++) {
        int src_idx = ((height - 1 - (i + top)) * width) + (j + left);
        temp = (float)image[src_idx] * scale;
        result[idx] = (temp < 0) ? temp + 256 : temp;
    }
}
}
