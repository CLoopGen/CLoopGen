#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (width > 0) {
        dst[0] = (((dst[0]) > (30189) ? (30189) : (dst[0])) * 19077 - 39057361) >> 14;
        for (i = 1; i < width; i++) {
            int16_t prev = dst[i-1]; 
            int16_t clamped = (dst[i] > 30189) ? 30189 : dst[i];
            dst[i] = (clamped * 19077 - 39057361 + prev) >> 14;
        }
    }
}
