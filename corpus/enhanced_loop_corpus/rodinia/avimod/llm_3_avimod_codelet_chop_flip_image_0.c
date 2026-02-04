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
    // Variant 2: Strided memory access with indirect addressing via pointer arithmetic
    // Use pointers to traverse `result` and `image` with fixed strides to simulate strided access
    float *res_ptr = result;
    int row_offset, col_base;
    for (i = 0; i < height_new; i++) {
        row_offset = (height - 1 - (i + top)) * width;
        col_base = left;
        for (j = 0; j < width_new; j++) {
            temp = (float)image[row_offset + col_base + j] * scale;
            *(res_ptr++) = (temp < 0) ? temp + 256 : temp;
        }
    }
}
