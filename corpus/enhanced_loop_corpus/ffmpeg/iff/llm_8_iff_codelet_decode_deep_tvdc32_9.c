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
    // Variant 1: Increased computational intensity with unrolled inner loop and reduced trip count
    for (i = 0; i < src_size * 2; ) {
        int d = tvdc[((i & 1) ? (src[i >> 1] & 15) : (src[i >> 1] >> 4))];
        i++;
        if (d) {
            pixel += d;
            dst[y * linesize + x * 4 + plane] = pixel;
            x++;
        } else {
            if (i >= src_size * 2)
                return;
            d = ((i & 1) ? (src[i >> 1] & 15) : (src[i >> 1] >> 4)) + 1;
            i++;
            d = (d > (width - x) ? (width - x) : d);
            // Unroll the copy loop by factor of 2 to increase arithmetic operations
            for (j = 0; j < (d & ~1); j += 2) {  // Process two elements at a time
                dst[y * linesize + x * 4 + plane] = pixel;
                x++;
                dst[y * linesize + x * 4 + plane] = pixel;
                x++;
            }
            // Handle remaining element if d is odd
            if (j < d) {
                dst[y * linesize + x * 4 + plane] = pixel;
                x++;
            }
        }
        if (x >= width) {
            plane++;
            if (plane >= 4) {
                y++;
                if (y >= height)
                    return;
                plane = 0;
            }
            x = 0;
            pixel = 0;
            i = (i + 1) & ~1;
        }
    }
}
