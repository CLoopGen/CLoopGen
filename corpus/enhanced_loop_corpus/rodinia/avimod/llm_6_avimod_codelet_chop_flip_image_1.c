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
    float *res_ptr = result;
    for (i = 0; i < height_new; i++) {
        int row_src = (height - 1 - (i + top)) * width;
        for (j = 0; j < width_new; j++) {
            temp = (float)image[row_src + (j + left)];
            temp = (temp < 0) ? temp + 256 : temp;
            *(res_ptr++) = temp;
        }
    }
}
