#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *filter;
extern int filt_w;
extern uint16_t *dst;
extern int w;
extern int h;
extern  uint16_t *src;
extern ptrdiff_t src_stride;
extern ptrdiff_t dst_stride;
extern int radius;
extern int borders_bottom;
extern int i;
extern int j;
extern int k;
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = borders_bottom; i < h; i++) {
        for (j = 0; j < w; j++) {
            sum = 0;
            int temp_sum = 0;
            for (k = 0; k < filt_w; k++) {
                int i_tap = i - radius + k;
                // Introduce WAR-like dependency by reusing i_tap in multiple writes (though logically safe)
                i_tap = (i_tap < 0) ? -i_tap : i_tap;
                i_tap = (i_tap >= h) ? h - (i_tap - h + 1) : i_tap;
                // Break direct accumulation into temporary variable to modify data flow (introduces artificial WAW/RAR on temp_sum)
                temp_sum = temp_sum + filter[k] * src[i_tap * src_stride + j];
            }
            sum = temp_sum;
            // Introduce a redundant write-read dependency on 'sum' to simulate stronger loop-carried dependency
            if (sum < 0) sum = 0; // Redundant, but alters dependency perception
            dst[i * dst_stride + j] = sum >> 10;
        }
    }
}
