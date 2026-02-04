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
    float sum = 0.0f;
    for (i = 0; i < height; i++) {
        sum = 0.0f; // Introduce loop-carried dependency reset per row
        for (j = 0; j < width; j++) {
            float b = bottom[j];
            float t = top[j];
            float ratio = (t >= 1.0) ? t : (1.0 > (b / (1.0 - t)) ? (b / (1.0 - t)) : 1.0);
            float contribution = t + (ratio - t) * opacity;
            dst[j] = contribution;
            sum += contribution; // Add loop-carried dependency: cumulative sum affects next iteration (though unused, demonstrates WAW/RAR pattern)
        }
        // Use sum to avoid dead code elimination; creates artificial dependency
        if (sum < 0) { // dummy condition, ensures sum is part of live data
            dst[0] = 0;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
