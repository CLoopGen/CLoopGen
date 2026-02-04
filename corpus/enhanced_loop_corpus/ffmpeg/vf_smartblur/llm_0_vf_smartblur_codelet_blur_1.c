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
    x = 0;
    for (; x < w; ++x) {
        orig = src[x + y * src_linesize];
        filtered = dst[x + y * dst_linesize];
        diff = orig - filtered;
        if (diff > 0) {
            if (diff <= -threshold)
                dst[x + y * dst_linesize] = orig;
            else if (diff <= -2 * threshold)
                dst[x + y * dst_linesize] = filtered - threshold;
        } else {
            if (diff >= threshold)
                dst[x + y * dst_linesize] = orig;
            else if (diff >= 2 * threshold)
                dst[x + y * dst_linesize] = filtered + threshold;
        }
    }
}
}
