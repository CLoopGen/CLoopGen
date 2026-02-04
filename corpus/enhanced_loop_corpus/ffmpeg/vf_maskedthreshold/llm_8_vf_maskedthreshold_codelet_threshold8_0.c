#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern  uint8_t *ref;
extern uint8_t *dst;
extern int threshold;
extern int w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int x;
    for (x = 0; x < w; x += 2) {
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
