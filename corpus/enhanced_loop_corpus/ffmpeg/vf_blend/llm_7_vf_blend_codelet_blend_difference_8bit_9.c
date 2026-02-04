#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern ptrdiff_t top_linesize;
extern  uint8_t *bottom;
extern ptrdiff_t bottom_linesize;
extern uint8_t *dst;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < height; i++) {
        uint8_t temp_sum[4096]; // Assuming max width is 4096 for stack safety; could be dynamically allocated if needed
        for (j = 0; j < width; j++) {
            int diff = top[j] - bottom[j];
            int abs_diff = diff >= 0 ? diff : -diff;
            temp_sum[j] = (uint8_t)(top[j] + (abs_diff - top[j]) * opacity);
        }
        for (j = 0; j < width; j++) {
            dst[j] = temp_sum[j];
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
