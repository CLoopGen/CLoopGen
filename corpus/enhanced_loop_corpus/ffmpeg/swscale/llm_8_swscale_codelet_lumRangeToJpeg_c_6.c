#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < width; i += 2) {
        if (i + 1 < width) {
            dst[i] = (((dst[i]) > (30189) ? (30189) : (dst[i])) * 19077 - 39057361) >> 14;
            dst[i+1] = (((dst[i+1]) > (30189) ? (30189) : (dst[i+1])) * 19077 - 39057361) >> 14;
        } else {
            dst[i] = (((dst[i]) > (30189) ? (30189) : (dst[i])) * 19077 - 39057361) >> 14;
        }
    }
}
