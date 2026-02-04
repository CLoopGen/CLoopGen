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
int total_pixels = w * h;
for (int idx = 0; idx < total_pixels; ++idx) {
    y = idx / w;
    x = idx % w;
    orig = src[x + y * src_linesize];
    filtered = dst[x + y * dst_linesize];
    diff = orig - filtered;
    int abs_diff = diff >= 0 ? diff : -diff;
    if (abs_diff >= threshold) {
        if (abs_diff >= 2 * threshold) {
            if (diff > 0)
                dst[x + y * dst_linesize] = filtered - threshold;
            else
                dst[x + y * dst_linesize] = filtered + threshold;
        } else {
            dst[x + y * dst_linesize] = orig;
        }
    }
}
}
