#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < width; i++) {
        int16_t val = dst[i];
        int16_t clamped = val;
        if (val > 30189) {
            clamped = 30189;
        }
        dst[i] = (clamped * 19077 - 39057361) >> 14;
    }
}
