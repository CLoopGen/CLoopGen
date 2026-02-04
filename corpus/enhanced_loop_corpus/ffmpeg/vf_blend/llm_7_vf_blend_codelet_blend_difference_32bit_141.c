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
    float diff, abs_diff, contribution;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j += 2) {
            // Introduce pipelined access with unrolled dependency chain
            if (j + 1 < width) {
                // Process two elements with separated data dependencies to reduce WAR/WAW hazards
                diff = top[j] - bottom[j];
                abs_diff = diff >= 0 ? diff : -diff;
                contribution = (abs_diff - top[j]) * opacity;
                dst[j] = top[j] + contribution;

                diff = top[j+1] - bottom[j+1];
                abs_diff = diff >= 0 ? diff : -diff;
                contribution = (abs_diff - top[j+1]) * opacity;
                dst[j+1] = top[j+1] + contribution;
            } else {
                // Handle odd-width edge case
                diff = top[j] - bottom[j];
                abs_diff = diff >= 0 ? diff : -diff;
                dst[j] = top[j] + (abs_diff - top[j]) * opacity;
            }
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
