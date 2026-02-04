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
for (y = 0; y < h; y += 2) {
    for (x = 0; x < w; x += 2) {
        for (int dy = 0; dy < 2 && (y + dy) < h; ++dy) {
            for (int dx = 0; dx < 2 && (x + dx) < w; ++dx) {
                int py = y + dy;
                int px = x + dx;
                orig = src[px + py * src_linesize];
                filtered = dst[px + py * dst_linesize];
                diff = orig - filtered;
                if (diff > 0) {
                    if (diff > 2 * threshold)
                        dst[px + py * dst_linesize] = orig;
                    else if (diff > threshold)
                        dst[px + py * dst_linesize] = orig - threshold;
                } else {
                    if (-diff > 2 * threshold)
                        dst[px + py * dst_linesize] = orig;
                    else if (-diff > threshold)
                        dst[px + py * dst_linesize] = orig + threshold;
                }
            }
        }
    }
}
}
