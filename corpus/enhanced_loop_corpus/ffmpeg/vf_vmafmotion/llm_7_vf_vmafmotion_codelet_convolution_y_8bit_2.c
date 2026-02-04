#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *filter;
extern int filt_w;
extern uint16_t *dst;
extern int w;
extern  uint8_t *src;
extern ptrdiff_t src_stride;
extern ptrdiff_t dst_stride;
extern int radius;
extern int borders_top;
extern int borders_bottom;
extern int i;
extern int j;
extern int k;
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = borders_top; i < borders_bottom; i++) {
        for (j = 0; j < w; j++) {
            sum = filter[0] * src[(i - radius) * src_stride + j]; // Initialize sum to break uniform recurrence
            // Unroll the first iteration to introduce non-uniform data flow
            for (k = 1; k < filt_w; k++) {
                // Create a chain of dependencies where each k depends on the previous sum
                // This strengthens loop-carried dependency in k-loop (RAW)
                int current_val = filter[k] * src[(i - radius + k) * src_stride + j];
                sum = sum + current_val; // Sequential update with enforced order
            }
            // Store result with fixed right-shift
            dst[i * dst_stride + j] = sum >> 8;
        }
    }
    // Eliminate any possibility of concurrent execution in k-dimension due to enforced sequential sum update
}
