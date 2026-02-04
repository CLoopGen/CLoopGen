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
for (i = 0; i < height; i += 2) {
    if (i + 1 < height) {
        for (j = 0; j < width; j++) {
            // Process two rows simultaneously to increase arithmetic intensity
            float diff_curr = top[j] - bottom[j];
            float abs_diff_curr = diff_curr >= 0 ? diff_curr : -diff_curr;
            dst[j] = top[j] + (abs_diff_curr - top[j]) * opacity;

            float diff_next = (top + top_linesize)[j] - (bottom + bottom_linesize)[j];
            float abs_diff_next = diff_next >= 0 ? diff_next : -diff_next;
            (dst + dst_linesize)[j] = (top + top_linesize)[j] + 
                (abs_diff_next - (top + top_linesize)[j]) * opacity;
        }
        dst += 2 * dst_linesize;
        top += 2 * top_linesize;
        bottom += 2 * bottom_linesize;
    } else {
        // Handle last row if height is odd
        for (j = 0; j < width; j++) {
            float diff = top[j] - bottom[j];
            float abs_diff = diff >= 0 ? diff : -diff;
            dst[j] = top[j] + (abs_diff - top[j]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
}
