#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t top_linesize;
extern ptrdiff_t bottom_linesize;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern  float *top;
extern  float *bottom;
extern float *dst;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *top_row = top;
    float *bottom_row = bottom;
    float *dst_row = dst;
    for (i = 0; i < height; i++) {
        float *top_ptr = top_row;
        float *bottom_ptr = bottom_row;
        float *dst_ptr = dst_row;
        for (j = 0; j < width; j += 2) {
            if (j + 1 < width) {
                dst_ptr[j] = top_ptr[j] + (((bottom_ptr[j] < 0.5) ? 
                    ((top_ptr[j]) > (2 * bottom_ptr[j]) ? (2 * bottom_ptr[j]) : (top_ptr[j])) : 
                    ((top_ptr[j]) > (2 * (bottom_ptr[j] - 0.5)) ? (top_ptr[j]) : (2 * (bottom_ptr[j] - 0.5)))) - top_ptr[j]) * opacity;

                dst_ptr[j+1] = top_ptr[j+1] + (((bottom_ptr[j+1] < 0.5) ? 
                    ((top_ptr[j+1]) > (2 * bottom_ptr[j+1]) ? (2 * bottom_ptr[j+1]) : (top_ptr[j+1])) : 
                    ((top_ptr[j+1]) > (2 * (bottom_ptr[j+1] - 0.5)) ? (top_ptr[j+1]) : (2 * (bottom_ptr[j+1] - 0.5)))) - top_ptr[j+1]) * opacity;
            } else {
                dst_ptr[j] = top_ptr[j] + (((bottom_ptr[j] < 0.5) ? 
                    ((top_ptr[j]) > (2 * bottom_ptr[j]) ? (2 * bottom_ptr[j]) : (top_ptr[j])) : 
                    ((top_ptr[j]) > (2 * (bottom_ptr[j] - 0.5)) ? (top_ptr[j]) : (2 * (bottom_ptr[j] - 0.5)))) - top_ptr[j]) * opacity;
            }
        }
        top_row += top_linesize;
        bottom_row += bottom_linesize;
        dst_row += dst_linesize;
    }
}
