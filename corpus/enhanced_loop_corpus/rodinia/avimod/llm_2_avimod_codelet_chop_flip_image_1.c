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
    // Variant 1: Consecutive Memory Access with Pointer Arithmetic
    float *res_ptr = result;
    char *img_base = image + ((height - 1 - top) * width) + left;
    int img_row_stride = -width; // Moving upwards in the original image

    for (i = 0; i < height_new; i++) {
        char *row_ptr = img_base + (i * img_row_stride);
        for (j = 0; j < width_new; j++) {
            temp = (float)row_ptr[j];
            *res_ptr++ = (temp < 0) ? temp + 256 : temp;
        }
    }
}
