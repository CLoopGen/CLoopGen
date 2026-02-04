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
    float *res_base = result;
    float temp_val;
    int img_idx;
    for (i = 0; i < height_new; i++) {
        int h_offset = (height - 1 - (i + top)) * width;
        float *res_row = res_base + i * width_new;
        for (j = 0; j < width_new; j++) {
            img_idx = h_offset + (j + left);
            temp_val = (float)image[img_idx] * scale;
            res_row[j] = (temp_val < 0) ? temp_val + 256.0f : temp_val;
        }
    }
}
