#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int threshold;
extern int w;
extern  uint16_t *src;
extern  uint16_t *ref;
extern uint16_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int x = 0; x < w; x += 2) {
        int diff1 = src[x] - ref[x];
        int abs_diff1 = diff1 >= 0 ? diff1 : -diff1;
        dst[x] = abs_diff1 <= threshold ? src[x] : ref[x];

        if (x + 1 < w) {
            int diff2 = src[x+1] - ref[x+1];
            int abs_diff2 = diff2 >= 0 ? diff2 : -diff2;
            dst[x+1] = abs_diff2 <= threshold ? src[x+1] : ref[x+1];
        }
    }
}
