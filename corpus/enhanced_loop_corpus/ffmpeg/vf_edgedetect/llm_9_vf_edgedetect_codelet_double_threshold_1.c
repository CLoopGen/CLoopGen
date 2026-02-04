#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int low;
extern int high;
extern int w;
extern int h;
extern uint8_t *dst;
extern int dst_linesize;
extern  uint8_t *src;
extern int src_linesize;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 2; j < h - 2; j += 2) {
    for (i = 2; i < w - 2; i += 2) {
        uint8_t val = src[i];
        if (val > high) {
            dst[i] = val;
        } else if (val > low) {
            int neighbors = (src[-src_linesize + i - 1] > high) + (src[-src_linesize + i] > high) + (src[-src_linesize + i + 1] > high) +
                           (src[i - 1] > high) + (src[i + 1] > high) +
                           (src[src_linesize + i - 1] > high) + (src[src_linesize + i] > high) + (src[src_linesize + i + 1] > high);
            dst[i] = (neighbors > 0) ? val : 0;
        } else {
            dst[i] = 0;
        }

        // Unroll adjacent pixels with bounds check simulation via conditionals
        if (i+1 < w - 2) {
            val = src[i+1];
            if (val > high) {
                dst[i+1] = val;
            } else if (val > low && (src[-src_linesize + i] > high || src[-src_linesize + i+1] > high || src[-src_linesize + i+2] > high ||
                                    src[i] > high || src[i+2] > high ||
                                    src[src_linesize + i] > high || src[src_linesize + i+1] > high || src[src_linesize + i+2] > high))
                dst[i+1] = val;
            else
                dst[i+1] = 0;
        }
    }
    dst += 2 * dst_linesize;
    src += 2 * src_linesize;
    if (j + 2 < h) {
        dst += dst_linesize;
        src += src_linesize;
    }
}
}
