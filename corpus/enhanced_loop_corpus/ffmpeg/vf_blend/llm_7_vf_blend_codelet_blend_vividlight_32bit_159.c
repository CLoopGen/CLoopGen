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
    float top_val, bottom_val, result_component;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            top_val = top[j];
            bottom_val = bottom[j];
            if (top_val < 0.5) {
                result_component = (2 * top_val) <= 0.0 ? (2 * top_val) :
                                  (0.0 > (1.0 - (1.0 - bottom_val) / (2 * top_val))) ? 0.0 :
                                  (1.0 - (1.0 - bottom_val) / (2 * top_val));
            } else {
                double t_adj = 2 * (top_val - 0.5);
                result_component = t_adj >= 1.0 ? t_adj :
                                  (1.0 > (bottom_val / (1.0 - t_adj))) ? (bottom_val / (1.0 - t_adj)) : 1.0;
            }
            dst[j] = top_val + (result_component - top_val) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
