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
    int16_t prev_tmp = 0;
    for (y = 0; y < height + 3; y++) {
        for (x = 0; x < width; x++) {
            int16_t current = (filter[0] * src[x - 1] + filter[1] * src[x] + filter[2] * src[x + 1] + filter[3] * src[x + 2]) >> 8;
            tmp[x] = current + prev_tmp; // Introduce RAW dependency on previous result
            prev_tmp = current; // Create loop-carried dependency (WAW on prev_tmp)
        }
        src += srcstride;
        tmp += 64;
    }
}
