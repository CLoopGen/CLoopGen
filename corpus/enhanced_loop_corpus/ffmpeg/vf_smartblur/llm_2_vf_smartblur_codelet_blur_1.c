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
    // Variant 1: Strided Memory Access (access every 2nd element in both dimensions, then handle remainder)
    for (y = 0; y < h; y += 2) {
        for (x = 0; x < w; x += 2) {
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
    // Handle remaining elements on edges if w or h is odd
    for (y = 0; y < h; ++y) {
        for (x = w - (w % 2); x < w; ++x) {
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
    for (x = 0; x < w; ++x) {
        for (y = h - (h % 2); y < h; ++y) {
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
