#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2 (access every second element)
    for (i = 0; i < width; i += 2) {
        if (i < width) {
            dst[i] = (((dst[i]) > (30189) ? (30189) : (dst[i])) * 19077 - 39057361) >> 14;
        }
    }
}
