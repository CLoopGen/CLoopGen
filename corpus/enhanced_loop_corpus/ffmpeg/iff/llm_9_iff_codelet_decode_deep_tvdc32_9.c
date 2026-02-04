#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int src_size;
extern int width;
extern int height;
extern int linesize;
extern  int16_t *tvdc;
extern int x;
extern int y;
extern int plane;
extern int8_t pixel;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with simplified control flow and increased effective trip count via padding
    for (i = 0; i < src_size * 3; i++) {  // Increased trip count but with early skips
        if (i >= src_size * 2) {
            // Padding phase: fill remaining pixels in current row-plane
            if (x < width) {
                dst[y * linesize + x * 4 + plane] = pixel;
                x++;
            } else {
                plane++;
                if (plane >= 4) {
                    y++;
                    if (y >= height) return;
                    plane = 0;
                }
                x = 0;
                if (plane == 0) return; // Only allow one full cycle after data end
            }
            continue;
        }

        int idx = i >> 1;
        int shift = (i & 1) ? 0 : 4;
        int val = (src[idx] >> shift) & 15;
        int d = tvdc[val];

        if (d) {
            pixel += d;
            dst[y * linesize + x * 4 + plane] = pixel;
            x++;
        } else {
            if (i + 1 >= src_size * 2) {
                i++;
                continue;
            }
            i++; // consume extra token
            int run_length = ((i & 1) ? (src[i >> 1] & 15) : (src[i >> 1] >> 4)) + 1;
            run_length = (run_length > (width - x)) ? (width - x) : run_length;
            // Simplified single-step write without complex addressing math
            for (j = 0; j < run_length; j++) {
                dst[y * linesize + x * 4 + plane] = pixel;
                x++;
            }
        }

        // Coalesced boundary check with fewer conditional layers
        if (x >= width) {
            x = 0;
            pixel = 0;
            if (++plane >= 4) {
                plane = 0;
                if (++y >= height)
                    return;
            }
            i = (i + 1) & ~1; // Align i to even index for next symbol
        }
    }
}
