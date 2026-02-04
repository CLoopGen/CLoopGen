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
    // Variant 2: Strided Memory Access with Reversed Inner Loop and Stride Optimization
    int total_elements = height_new * width_new;
    int img_offset_base = ((height - 1 - top) * width) + left;
    int img_row_step = -width;
    int stride = 4; // Process 4 elements at a time if possible (unrolled-like access pattern)

    // Linear traversal using combined index with strided access
    for (int idx = 0; idx < total_elements; idx += stride) {
        for (int s = 0; s < stride; s++) {
            int linear_idx = idx + s;
            if (linear_idx >= total_elements) break;

            i = linear_idx / width_new;
            j = linear_idx % width_new;

            int img_idx = (img_offset_base + (i * img_row_step)) + j;
            temp = (float)image[img_idx];
            result[linear_idx] = (temp < 0) ? temp + 256 : temp;
        }
    }
}
