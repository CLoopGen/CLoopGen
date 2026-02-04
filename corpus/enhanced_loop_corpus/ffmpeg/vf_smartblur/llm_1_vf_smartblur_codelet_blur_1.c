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
        int index = x + y * src_linesize;
        orig = src[index];
        filtered = dst[index];
        diff = orig - filtered;
        if (diff > 0) {
            if (diff <= -threshold)
                dst[index] = orig;
            else if (diff <= -2 * threshold)
                dst[index] = filtered - threshold;
        } else {
            if (diff >= threshold)
                dst[index] = orig;
            else if (diff >= 2 * threshold)
                dst[index] = filtered + threshold;
        }
    }
}
}
