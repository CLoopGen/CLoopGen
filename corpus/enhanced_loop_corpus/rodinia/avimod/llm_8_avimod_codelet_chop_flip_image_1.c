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
for (i = 0; i < height_new; i += 2) {
    for (j = 0; j < width_new; j += 2) {
        int idx = (height - 1 - (i + top)) * width + (j + left);
        temp = (float)image[idx];
        float val = (temp < 0) ? temp + 256 : temp;
        result[i * width_new + j] = val;
        if (j + 1 < width_new) {
            temp = (float)image[idx + 1];
            result[i * width_new + (j + 1)] = (temp < 0) ? temp + 256 : temp;
        }
        if (i + 1 < height_new) {
            int idx2 = (height - 1 - (i + 1 + top)) * width + (j + left);
            temp = (float)image[idx2];
            result[(i + 1) * width_new + j] = (temp < 0) ? temp + 256 : temp;
            if (j + 1 < width_new) {
                temp = (float)image[idx2 + 1];
                result[(i + 1) * width_new + (j + 1)] = (temp < 0) ? temp + 256 : temp;
            }
        }
    }
}
}
