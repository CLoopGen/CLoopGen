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
    // Variant 2: Unrolled Inner Loop with Strided Accumulation
    // We restructure the accumulation to process multiple filter taps at once (unroll by 2)
    // and use direct offset indexing with precomputed strides to expose memory-level parallelism.
    // This assumes filt_w is even; if not, original loop handles remainder implicitly via condition.

    for (i = borders_top; i < borders_bottom; i++) {
        for (j = 0; j < w; j++) {
            sum = 0;
            int k_unroll = filt_w & ~1; // Round down to nearest even number
            for (k = 0; k < k_unroll; k += 2) {
                sum += filter[k] * src[(i - radius + k) * src_stride + j];
                sum += filter[k+1] * src[(i - radius + k + 1) * src_stride + j];
            }
            // Handle remaining tap if filt_w was odd
            if (k < filt_w) {
                sum += filter[k] * src[(i - radius + k) * src_stride + j];
            }
            dst[i * dst_stride + j] = sum >> 8;
        }
    }
}
