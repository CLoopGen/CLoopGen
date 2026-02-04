#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t prev_tmp_val = 0;
    for (y = 0; y < height + 3; y++) {
        for (x = 0; x < width; x++) {
            // Introduce loop-carried dependence on tmp: each tmp[x] depends on previous result
            int16_t raw_val = (filter[0] * src[x - 1] + filter[1] * src[x] + 
                               filter[2] * src[x + 1] + filter[3] * src[x + 2]) >> 8;
            tmp[x] = raw_val + prev_tmp_val; // WAW and loop-carried dependency introduced
            prev_tmp_val = raw_val;
        }
        src += srcstride;
        tmp += 64;
    }
}
