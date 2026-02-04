#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  int dst_linesize;
extern  uint8_t *src;
extern  int src_linesize;
extern  int w;
extern  int h;
extern  int threshold;
extern int x;
extern int y;
extern int orig;
extern int filtered;
extern int diff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive (Linearized) Memory Access with pointer arithmetic
    uint8_t *src_ptr = src;
    uint8_t *dst_ptr = dst;
    int line_offset = 0;

    for (y = 0; y < h; ++y) {
        line_offset = y * src_linesize;
        src_ptr = src + line_offset;
        dst_ptr = dst + line_offset;
        for (x = 0; x < w; ++x) {
            orig = *(src_ptr + x);
            filtered = *(dst_ptr + x);
            diff = orig - filtered;
            if (diff > 0) {
                if (diff > 2 * threshold)
                    *(dst_ptr + x) = orig;
                else if (diff > threshold)
                    *(dst_ptr + x) = orig - threshold;
            } else {
                if (-diff > 2 * threshold)
                    *(dst_ptr + x) = orig;
                else if (-diff > threshold)
                    *(dst_ptr + x) = orig + threshold;
            }
        }
    }
}
