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
    int y, x;
    int orig_val, filtered_val, diff_val;
    uint8_t *dst_line, *src_line;

    for (y = 0; y < h; ++y) {
        dst_line = dst + y * dst_linesize;
        src_line = src + y * src_linesize;
        for (x = 0; x < w; ++x) {
            orig_val = src_line[x];
            filtered_val = dst_line[x];
            diff_val = orig_val - filtered_val;

            if (diff_val > 0) {
                if (diff_val <= -threshold)
                    dst_line[x] = orig_val;
                else if (diff_val <= -2 * threshold)
                    dst_line[x] = filtered_val - threshold;
            } else {
                if (diff_val >= threshold)
                    dst_line[x] = orig_val;
                else if (diff_val >= 2 * threshold)
                    dst_line[x] = filtered_val + threshold;
            }
        }
    }
}
