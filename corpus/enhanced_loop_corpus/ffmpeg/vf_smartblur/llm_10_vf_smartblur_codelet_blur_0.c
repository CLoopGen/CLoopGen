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
for (y = 0; y < h; ++y) {
    for (x = 0; x < w; ++x) {
        orig = src[x + y * src_linesize];
        filtered = dst[x + y * dst_linesize];
        diff = orig - filtered;

        if (diff == 0) continue;

        int abs_diff = diff < 0 ? -diff : diff;

        if (abs_diff <= threshold) {
            // Small difference: apply partial correction
            dst[x + y * dst_linesize] = diff > 0 ? orig - threshold : orig + threshold;
        } else if (abs_diff <= 2 * threshold) {
            // Medium difference: keep corrected value
            dst[x + y * dst_linesize] = diff > 0 ? orig - threshold : orig + threshold;
        } else {
            // Large difference: reset to original
            dst[x + y * dst_linesize] = orig;
        }
    }
}
}
